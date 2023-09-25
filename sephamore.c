#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int svar = 99;
int rc = 0,wc=0,rdc=0;
sem_t wrt,mutex;

void *reader (void *p)
{
sem_wait(&mutex);
rc++;
rdc++;
if (rc==1)
sem_wait(&wrt);
sem_post(&mutex);
printf("\nThe value of svar %d: %d\n",rdc,svar);
sem_wait(&mutex);
rc--;
if (rc==0)
sem_post(&wrt);
sem_post(&mutex);
}

void *writer(void *p)
{
sem_wait(&wrt);
svar++;
wc++;
printf("\nThe new value of svar incremented  %d: %d\n",wc,svar);
sem_post(&wrt);

}

int main(){
sem_init(&wrt,0,1);
sem_init(&mutex,0,1);
int rnum,wnum,i;
printf("\nEnter number of readers and writers : ");
scanf("%d%d",&rnum,&wnum);

pthread_t readers[5], writers[5];

for(i=0;i<rnum;i++){
pthread_create(&readers[i],NULL,reader,NULL);
pthread_join(readers[i],NULL);
}

for(i=0;i<wnum;i++){
pthread_create(&writers[i],NULL,writer,NULL);
pthread_join(writers[i],NULL);
}

}