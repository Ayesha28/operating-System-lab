
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int f=6;
void MyThread(void*N)
{
	static int s=3;
	int l=1;
	int* n=(int*)N;
	f++;l++; s++;
	printf("Thread_id %d, Global %d, Static %d, Local %d\n",*n,f,s,l);

}
 int main()
 {
 	int n,i;
 	pthread_t tid;
 	for(i=0;i<3;i++)
 	pthread_create(&tid,NULL,MyThread,(void*)&tid);
 	pthread_exit(0);
 	return 0;
 }
