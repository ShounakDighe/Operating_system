#include<stdio.h>

int main(){

int At[10];
int Bt[10];
int Ct[10];
int Tat[10];
int Wt[10];
int St[10];
int Q;
int num;
int tBt[10];


printf("Enter total number of processes :");
scanf("%d",&num);

printf("Enter the Quantum time :");
scanf("%d",&Q);

for (int i=0;i<num;i++)
{
printf("Enter the Arrival Time %d :",i);
scanf("%d",&At[i]);
printf("Enter the Burst Time %d :",i);
scanf("%d",&Bt[i]);
tBt[i]=Bt[i];

}

int count=0;
int i=0;
int sum=0;

while(count<num)
{
if(tBt[i]>Q){
sum=sum+Q;
tBt[i]=tBt[i]-Q;
}
else if(tBt[i]<=Q && tBt[i]>0){
sum=sum+tBt[i];
Ct[i]=sum;
count++;
tBt[i]=0;
Tat[i]=Ct[i]-At[i];
Wt[i]=Tat[i]-Bt[i];

}
i++;
if(i==num)
{i=0;}
}


printf("\n\nPId\tAT\tBT\tCT\tTAT\tWT\n\n");

for(int i=0;i<num;i++)
{printf("P%d\t%d\t%d\t%d\t%d\t%d\n\n",i,At[i],Bt[i],Ct[i],Tat[i],Wt[i]);}
}