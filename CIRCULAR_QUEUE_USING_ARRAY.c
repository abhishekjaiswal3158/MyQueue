#include <stdio.h>
#include<stdlib.h>

#define max 10

int cq[max];

int front=-1;
int rear=-1;

void enqueue(int *cq,int data){
    if (front==(rear+1)%max)
    {
        printf("\nQUEUE IS FULL\n");
    }
    else if(rear==-1){
        rear++;
        front++;
        cq[rear]=data;
    }
    
    else if(rear==max-1){
        rear=0;
        cq[rear]=data;
    }
    else{
        rear++;
        cq[rear]=data;
    }
    
}

int dequeue(int *cq){
    int data;
    if(rear==-1){
        printf("\nQUEUE IS EMPTY\n");
    }
    else{
        data =cq[front];
    }
    if(front==max-1){
        if(front==rear){
            front=rear=-1;
        }
        else{
            front=0;
        }
    }
    else
    {
         if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
        
    }
        return data;
}

void display(int *cq){
if(rear==-1){
    printf("!!!!!!!!!!!QUEUE IS EMPTY!!!!!!!");
}

 
 else if(front<=rear){
     printf("\nTHE ELEMENT IN QUEUE=");
    for(int i=front;i<=rear;i++){
        printf("%d ",cq[i]);
    }
}
else if(front>rear){
    printf("\nTHE ELEMENT IN QUEUE=");
    for(int i=front;i<=max-1;i++){
        printf("%d ",cq[i]);
    }
    for(int i=0;i<=rear;i++){
        printf("%d ",cq[i]);
    }
}
printf("\n");
}

int main(){
    printf("<<<<<<<<<<<<<<<<----------------WELCOME TO MY CIRCULAR QUEUE--------------->>>>>>>>>>>>>>>>>\n");
    while (1)
    {
      printf("<<<<<<<<<<-----------MENU---------->>>>>>>>>>>>>>\n1->ENQUEUE\n2->DEQUEUE\n3->DISPLAY\n4->EXIT\n");
      printf("ENTER THE NUMBER=");
      int num;
      scanf("%d",&num);
      switch(num){
      case 1:
              printf("ENTER THE NUMBER THAT U WANT TO ENQUEQE=");
              int data;
              if(front!=(rear+1)%max){
              scanf("%d",&data);
              enqueue(&cq[0],data);}
              else{
                  printf("!!!!!!!!!QUEUE IS FULL!!!!!!!!!!!!\n");
              }
              break;

      case 2: 
      if(rear!=-1){
      int deleted_data=dequeue(&cq[0]);
              printf("\nTHE DEQUEUE ELEMENT =%d\n",deleted_data);}
              else
              {
                  printf("!!!!!!!!!!!!!QUEUE IS EMPTY!!!!!!!!!!!\n");
              }
              
              break;
      case 3:display(&cq[0]);
              break;
      case 4: exit(0);
      default: printf("YOU HAVE ENTERED INVALID NUMBER");      

      }
    }
    return 0;
}



