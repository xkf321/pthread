#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* thread_1(void *arg)
{
	printf("This is thread_1 and arg = %d.\n",*(int *)arg);
	*(int *)arg-=1;
	//return arg;
	pthread_exit(arg);
}

void* thread_2(void *arg)
{
	printf("This is thread_2 and arg = %d.\n",*(int *)arg);
	//return 0;
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pthread_t id_1,id_2;
	int ret;
	void *rt=NULL;
	int arg=10; //传个线程的参数
	printf("test for thread\n");
	/*创建线程1*/
	ret=pthread_create(&id_1,NULL,(void *)thread_1,&arg);
	if(ret != 0)
	{
		perror("pthread_1 create");
		return -1;
	}
	/*创建线程2*/
	ret=pthread_create(&id_2,NULL,(void *)thread_2,&arg);
	if(ret != 0)
	{
		perror("pthread_2 create");
		return -1;
	}	
	
	pthread_join(id_1,&rt);
	//sleep(1);
	printf("线程返回的值 = %d\n",*(int *)rt);
	return 0;
	
}
