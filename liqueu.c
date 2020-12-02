#include <assert.h>
#include"liqueu.h"
#include<stdlib.h>
#include <stdint.h>


Queue  queue_new(){
Queue  q ={NULL,NULL,0};
return q;
}

uint8_t   queue_empty(Queue  *q){
assert(q!=NULL);
return (q->count==0);
}


static Node*   _get_new_node_(int32_t ele){
Node *newnode=(Node*)malloc(sizeof(Node));
newnode->data=ele;
newnode->next=NULL;

return newnode;
}

Queue*  queue_add(Queue  *q,int32_t ele,QueueResult  *res){
assert(q!=NULL);
Node  *newnode=_get_new_node_(ele);


if (q->rear!=NULL){  //there is atelast one element in the queue
    q->rear->next=newnode;
    q->rear=newnode;

}

else{
q->rear=q->front=newnode;
}
++q->count;
return q;
}


Queue*  queue_delete(Queue*  q,QueueResult  *res){
assert(q!=NULL);
Node *temp;
if(q->front !=NULL){
    temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    --q->count;
    res->data=temp->data;
    res->status=QUEUE_OK;
    free(temp);
}else{
res->status=QUEUE_EMPTY;
}
return q;
}


uint32_t   queue_length(Queue *q){
assert(q!=NULL);
return q->count;
}
