#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
int arr[100];
void *child(void *num)
{
 	int i;
 	int *d=(int*)num;
 	int n=*d;
 	arr[0]=0;
 	arr[1]=1;
 	for(i=2;i<n;i++)
	{ 
   		arr[i]=arr[i-1]+arr[i-2];
 	}
}
void *parent()
{
	int num,i;
	printf("Enter the number of terms in the Fibonacci series :");
	scanf("%d",&num);
	pthread_t th1;
	pthread_create(&th1,NULL,child,&num);
	pthread_join(th1,NULL);
 	wait(NULL);  
  	printf("\n Fibonacci Series is:");
  	for(i=0;i<num;i++)
  	{
   		printf("%d  ",arr[i]);
  	}
}
int main()
{
	pthread_t th;
	pthread_create(&th,NULL,parent,NULL);
	pthread_join(th,NULL);
}
