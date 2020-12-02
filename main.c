#include <stdio.h>
#include <stdlib.h>
#include  "liqueu.h"
#include<assert.h>



void test_empty(){
Queue q1=queue_new();
Queue *q=&q1;
assert(queue_empty(q));
}

void test_add(){
Queue q1=queue_new();
Queue *q=&q1;
QueueResult res;

q=queue_add(q,10,&res);
q=queue_add(q,20,&res);
q=queue_add(q,30,&res);
q=queue_add(q,40,&res);
assert(queue_length(q)==2);
//assert(res.status ==QUEUE_FULL);
//assert(queue_full(q));
}


void test_Qdelete(){
Queue q1=queue_new();
Queue *q=&q1;
QueueResult res;

q=queue_add(q,10,&res);
q=queue_add(q,20,&res);
q=queue_add(q,30,&res);

assert (queue_length(q)==3);
q=queue_delete(q, &res);
assert(res.data==10);
assert (queue_length(q)==2);
q=queue_delete(q, &res);
q=queue_delete(q, &res);
q=queue_delete(q, &res);
assert(res.status==QUEUE_EMPTY);
assert(queue_empty(q));
assert(queue_length(q)==0);
}
int main()
{
   // test_empty();
    //test_add();
    test_Qdelete();
    return 0;
}
