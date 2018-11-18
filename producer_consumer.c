#include<stdio.h>
#include<stdlib.h>
int full=0,empty=3,x=0,semaphore=1;
int signal(int s){
  return ++s;
}
int wait(int s){
  return --s;
}
void producer(){
  semaphore=wait(semaphore);

  full=wait(full);
  empty=wait(empty);
  semaphore=signal(semaphore);
  x++;
  printf("producer produces the item %d \n",x);

}
void consumer(){
  semaphore=wait(semaphore);
  full=signal(full);
  empty=wait(empty);
  printf("consumer consumes the item %d \n",x);
  x--;

  semaphore=signal(semaphore);
}
int main(){
  int k;
  printf("enter your choice \n producer \n consumer \n exit");
  while(1){

  scanf("%d",&k);
  switch(k){
  case 1:
    if(semaphore>=1 && empty!=0){
      producer();
    }
    else{
      printf("buffer is full");
    }
    break;
  case 2:
    if(semaphore>=1 && full!=0){
      consumer();
    }
    else{
      printf("buffer is empty");
    }
    break;
    case 3:
     exit(0);
  }
}
return (0);
}
