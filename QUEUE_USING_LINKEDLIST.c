#include <stdio.h>
#include <stdlib.h>

typedef struct node queue_node;
struct node
{
    int data;
    queue_node *next;
};
queue_node *rear = NULL;
queue_node *front = NULL;

void enqueue(queue_node **rear, queue_node **front, int data)
{
    queue_node *newnode = (queue_node *)malloc(sizeof(queue_node));
    newnode->data = data;
    newnode->next = NULL;
    if (newnode == NULL)
    {
        printf("QUEUE IS FULL");
    }
    else if (*rear == NULL)
    {
        *rear = newnode;
        *front = newnode;
    }
    else
    {
        (*rear)->next = newnode;
        *rear = (*rear)->next;
    }
}

int dequeue(queue_node **rear, queue_node **front)
{
    if (*front == NULL)
    {
        printf("QUEUE IS EMPTY");
    }
    queue_node *temp = (*front);
    int data = temp->data;
    if (*front == *rear)
    {
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
    }

    return data;
}

void display(queue_node **rear, queue_node **front)
{
    if (*rear == NULL)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("THE ELEMENT IN THE QUEUE=");
        queue_node *temp = *front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    printf("<<<<<<<<<<<<<<<<----------------WELCOME TO MY QUEUE--------------->>>>>>>>>>>>>>>>>\n");
    while (1)
    {
        printf("<<<<<<<<<<-----------MENU---------->>>>>>>>>>>>>>\n1->ENQUEUE\n2->DEQUEUE\n3->DISPLAY\n4->EXIT\n");
        printf("ENTER THE NUMBER=");
        int num;
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("ENTER THE NUMBER THAT U WANT TO ENQUEQE=");
            int data;
            scanf("%d", &data);
            enqueue(&rear, &front, data);
            break;
        case 2:
            if (front != NULL)
            {
                int deleted_data = dequeue(&rear, &front);
                printf("\nTHE DEQUEUE ELEMENT =%d\n", deleted_data);
            }
            else
            {
                printf("!!!!!!!!!!!!!QUEUE IS EMPTY!!!!!!!!!!!\n");
            }

            break;
        case 3:
            display(&rear, &front);
            break;
        case 4:
            exit(0);
        default:
            printf("YOU HAVE ENTERED INVALID NUMBER");
        }
    }
    return 0;
}
