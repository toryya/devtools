#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data; // данные
    struct node *next; //адрес следующего узла
} node;

typedef struct queue // хранение кол-ва узлов, передней и задней части
{
    node *head;
    node *tail;
}queue;


int empty(queue *q) // проверка пуста ли очередь. задняя часть null
{
    return (q->tail == NULL);
}

void push(queue *q, int value)
{
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp->data = value;
    tmp->next = NULL;
    if(!empty(q))
    {
        q->tail->next = tmp;
    }
    else
    {
        q->head = tmp;
    }
    q->tail = tmp;
}

int pop(queue *q)
{
    node *tmp;
    tmp = malloc(sizeof(node));
    int n = q->head->data;
    tmp = q->head;
    q->head = q->head->next;

    if(q->head == NULL){
        q->tail = NULL;
    }
    free(tmp);
    return n;
}


int main()
{
    int n;
    scanf("%d", &n);
    queue q;
    (&q)->head = NULL; // инициализация
    (&q)->tail = NULL;

    int arr[n]; 
    int count=0;

    for (int i=0; i<n; i++){
        char oper;
        scanf ("%c", &oper);

        while(oper != '+' &&  oper != '-'){
            scanf ("%c", &oper);
        }

        if (oper == '+'){
            int value;
            scanf("%d", &value);
            push(&q, value);
        } else {
            arr[count] = pop(&q);
            count ++;
        }

    }
    for (int i = 0; i < count; i++){
        printf ("%d \n", arr[i]);
    }
    return 0;
}