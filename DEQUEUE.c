#include <stdio.h>
#include <stdlib.h>
#define max 5
int DEQUEUE[max];
int rear1 = -1;
int rear2 = max;
int front1 = -1;
int front2 = max;

void enque(int *dq, int *rear1, int *front1, int data)
{

    if (*rear1 == -1)
    {
        (*rear1)++;
        (*front1)++;
        dq[*rear1] = data;
    }
    else
    {
        (*rear1)++;
        dq[*rear1] = data;
    }
}

int deque(int *dq, int *rear1, int *front1)
{
    int data = dq[*front1];
    if (*front1 == *rear1)
    {
        *front1 = -1;
        *rear1 = -1;
    }
    else
    {
        (*front1)++;
    }
    return data;
}

void displayFront(int *dq, int *rear1, int *front1)
{
    if(*front1==-1){
        printf("!!!!!!!!!FRONT QUEUE IS EMPTY!!!!!!!!!\n");
    }
    else{
    printf("ELEMENT IN THE FRONT QUEUE=");
    for (int i = *front1; i <= *rear1; i++)
    {
        printf("%d ", dq[i]);
    }
    printf("\n");
}
}
void inject(int *dq, int *rear2, int *front2, int data)
{
    if (*rear2 == max)
    {
        (*rear2)--;
        (*front2)--;
        dq[*rear2] = data;
    }
    else
    {
        (*rear2)--;
        dq[*rear2] = data;
    }
    printf("rear=%d",*rear2);
    printf("front=%d",*front2);
}

int eject(int *dq, int *rear2, int *front2)
{
    int data = dq[*front2];
    if (*front2 == *rear2)
    {
        *front2 = max;
        *rear2 = max;
    }
    else
    {
        (*front2)--;
    }
    printf("rear=%d",*rear2);
    printf("front=%d",*front2);
    return data;
}

void displayEnd(int *dq, int *rear2, int *front2)
{
    if (*front2 == max)
    {
        printf("!!!!!!!!!!!END QUEUE IS EMPTY!!!!!!!!\n");
    }
    else
    {
        printf("ELEMENT IN THE END QUEUE=");
        for (int i = *front2; i >= *rear2; i--)
        {
            printf("%d ", dq[i]);
        }
        printf("\n");
    }
}

int main()
{
    printf("<<<<<<<<<<<<<----------WELCOME TO MY DOUBLY ENDED QUEUE----------->>>>>>>>>>>>>>>\n");
    while (1)
    {
        printf("<<<<<<<<<<<MENU>>>>>>>>>>\n1->ENQUEUE\n2->DEQUEUE\n3->INJECT\n4->EJECT\n5->DISPLAY FRONT\n6->DISPLAY END\n7->EXIT\n");
        printf("ENTER THE MENU NUMBER=");
        int t;
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            if (rear1 != rear2 - 1)
            {
                printf("ENTER THE NUMBER THAT YOU WANT TO ENQUEUE =");
                int data;
                scanf("%d", &data);
                enque(&DEQUEUE[0], &rear1, &front1, data);
            }
            else
            {
                printf("!!!!!!!QUEUE IS FULL!!!!!!!!!!\n");
            }
            break;
        case 2:
            if (front1 != -1)
            {
                int data = deque(&DEQUEUE[0], &rear1, &front1);
                printf("THE DEQUE ELEMENT =%d\n", data);
            }
            else
            {
                printf("!!!!!!!FRONT QUEUE IS EMPTY!!!!!!!!!!\n");
            }
            break;
        case 3:
            if (rear1 != rear2 - 1)
            {
                printf("ENTER THE NUMBER THAT YOU WANT TO INJECT =");
                int data;
                scanf("%d", &data);
                inject(&DEQUEUE[0], &rear2, &front2, data);
            }
            else
            {
                printf("!!!!!!!QUEUE IS FULL!!!!!!!!!!\n");
            }
            break;

        case 4:
            if (front2 != max)
            {
                int data = eject(&DEQUEUE[0], &rear2, &front2);
                printf("THE EJECT ELEMENT =%d\n", data);
            }
            else
            {
                printf("!!!!!!!QUEUE IS EMPTY!!!!!!!!!!\n");
            }
            break;

        case 5:
            displayFront(&DEQUEUE[0], &rear1, &front1);
            break;
        case 6:
            displayEnd(&DEQUEUE[0], &rear2, &front2);
            break;
        case 7:
            exit(0);
        default:
            printf("INVALID NUMBER");
            break;
        }
    }
}