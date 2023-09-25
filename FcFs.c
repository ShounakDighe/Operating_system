#include <stdio.h>

int main()
{
int n,at[10], st[10], bt[10], ct[10], tat[10], wt[10], i;
printf("\nEnter number of processes: ");
scanf("%d",&n);

for (i=0;i<n;i++)
{
printf("\nEnter arrival time and burst time for process %d: ",i+1);
scanf("%d%d",&at[i],&bt[i]);
}

int idle=0;
float avgtat=0, avgwt=0;
printf("\nGantt chart: ");
st[0]=at[0];
for (i=0;i<n;i++)
{
ct[i]=st[i]+bt[i];
if (at[i+1]<=ct[i]){
st[i+1] = ct[i];
printf("|%d__P%d__%d|",st[i],i+1,ct[i]);
}
else{
st[i+1] = at[i+1];
idle += at[i+1]-ct[i];
printf("|%d__P%d__%d||__idle__|",st[i],i+1,ct[i]);
   }

tat[i]=ct[i]-at[i];
wt[i] = tat[i] - bt[i];
avgtat += tat[i];
avgwt += wt[i];
}

//printf("__P%d__%d|",i+1,sum);
avgtat/=n;
avgwt/=n;

printf("\n\nprocess no.\tAT\tBT\tCT\tTAT\tWT");
for (i=0;i<n;i++)
{
printf("\nprocess %d.\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
}
printf("\n\nIdle time = %d",idle);
printf("\n\nAverage TAT = %f",avgtat);
printf("\nAverage WT = %f\n\n",avgwt);
}