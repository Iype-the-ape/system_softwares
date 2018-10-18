#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,ar[100],n,head,seek=0;
  float avg;
  printf("Enter the head position");
  scanf("%d",&head);
  printf("Enter the size of queue");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter the queue");
    scanf("%d",&ar[i]);
  }
  printf("***FCFS SCHEDULING*** \n");
  printf("processed list is \n");

  for (i=0;i<n;i++){
    printf(" \n ");
    printf("%d ",ar[i]);
}
for(i=0;i<n;i++){
  if(i==0){
    seek+=abs(ar[i]-head);
  }
  else{
    seek+=abs(ar[i-1]-ar[i]);
  }
}
printf("\n ");
printf("seek time is %d",seek);
avg=seek/n;
printf(" \n average seek time is:%f ",avg);
}
