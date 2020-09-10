// the RACE conditions conditions exist in a program if the sequence in which the output 
//is produced is unpredictable because of the order in which the programs are executed .
//The following code illustrates this concept
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
    int i,j;
    i=fork();
    if(i==0)//child process
    {
        for(j=1;j<=10;j++)
         printf("Child here\n");
        exit(0);
    }
    else //parent process
    {
        for(j=1;j<=10;j++)
         printf("Parent here\n");

    }
   exit(0);
}