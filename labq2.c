#include<pthread.h>
#include<stdio.h>
void *mythread(void *arg)
{
 int x = *(int *)arg;
 int arr[x];
 int sum=0,avg;  
 int result;
 int i;
 printf("enter your marks\n");
 for(i=0;i<x;i++)
 {
   scanf("%d",&arr[i]);
 }
 printf("calculate avg :");
 for(i=0;i<x;i++)
 {
   sum=sum+arr[i];
 }
 avg=sum/x;
 result=avg;
 return ((void *)(long)result);

}
int main()
{
 int value;
 pthread_t tid;
 void *result;
 int output;
 printf("enter number of subject");
 scanf("%d",&value);
 pthread_create(&tid,NULL,mythread,(void *)&value);
 pthread_join(tid,(void **)&output);
 printf("%d\n",output);
 return 0;
}
