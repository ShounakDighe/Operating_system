#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
pid_t num_pid = fork();
if (num_pid<0){
printf("\nError,Child not created!"); //fork returns negative value if it fails to execute
}
if (num_pid==0){
sleep(5);
printf(" \nThis is the child process id : %d \n", getpid());
printf(" \nThis is the return value of fork() in child process : %d \n", num_pid);
printf(" \nThis is the process id of the child's parent : %d \n", getppid());

}
if (num_pid>0){
printf(" \nThis is the parent process id : %d \n", getpid());
printf(" \nThis is the return value of fork() in parent process : %d \n", num_pid);
printf(" \nThis is the process id of the parent's parent : %d \n", getppid());
}
return 0;
}