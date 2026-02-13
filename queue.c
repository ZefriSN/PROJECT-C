#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{

    int value;
    struct Node *next;
} Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
} queue;

queue *create_queue();
int size (queue *queue);
bool is_empty(queue *queue);
int peek(queue *queue, bool *status);
void enqueue(queue *queue, int value);
int dequeue(queue *queue, bool *status);
void destroy_queue(queue *queue);

int main(){
    queue *queue = create_queue();

    if (is_empty(queue)){
        printf("queue is Empty\n");
    }
    enqueue(queue, 4);
    if(!is_empty(queue)){
        printf("queue is not empty\n");
    }
    enqueue(queue, 5);
    enqueue(queue,6);
    printf(" queueu size = %d\n", size(queue));


    bool status = false;
    int value = 0;

    value = peek(queue, &status);
    if (status){
        printf("Peek succesfull: %d\n", value);
    }

        value = dequeue(queue, &status);
        if (status){
            printf("dequqeu is succcesful %d\n,",value);
        }


    return 0;
}





queue *create_queue(){
    queue *queue = malloc(sizeof(queue));

    queue-> head = NULL;
    queue-> tail = NULL;
    queue->size = 0;

    return queue;
}

int size (queue *queue){

    return queue->size;

}
bool is_empty(queue *queue){

    return (queue->size == 0);
}

int peek(queue *queue, bool *status){

    if (is_empty(queue)){
        *status = false;
        return 0;
    }
    *status = true;
    return queue->head->value;
}

void enqueue(queue *queue, int value){
    Node *newNode = malloc(sizeof(Node));

    newNode-> value = value;
    newNode->next = NULL;
    if (is_empty(queue)){
        queue->head = newNode;
        queue->tail = newNode;
    }else{
        queue->tail->next = newNode;
        queue->tail = newNode;
    }


    queue->size++;
}
int dequeue(queue *queue, bool *status){
    if(is_empty(queue)){
        *status = false;
        return 0;

    }
    *status = true;
    int value = queue->head->value;

    //delete node
    Node *oldHead = queue->head;
    
    if (queue->size == 1)
    {
        queue->head = NULL;
        queue -> tail= NULL;
    }else{
        queue->head = queue->head->next;

    }

    free(oldHead);

    queue->size--;
    return value;
}
void destroy_queue(queue *queue){

    Node *currentNode = queue->head;
    

    while(currentNode != NULL)
    {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(queue);
}
