#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int *fib;
void *myThreadFun(void *n)
{
    int *N=(int*)n;
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<*N;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
}

int main()
{
    pthread_t thread_id;
    int n;
    printf("enter number upto which you need fibonacci series : ");
    scanf("%d",&n);
    fib=(int*)malloc(n*sizeof(int));
    pthread_create(&thread_id, NULL, myThreadFun,(void*)&n);
    pthread_join(thread_id, NULL);
    for(int i=0;i<n;i++)
    printf("%d ",fib[i]);
    exit(0);
}
