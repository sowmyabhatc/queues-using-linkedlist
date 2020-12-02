#ifndef LIQUEU_H_INCLUDED
#define LIQUEU_H_INCLUDED
#include <stdint.h>

typedef enum{
QUEUE_OK=1,
QUEUE_EMPTY=2,
}Qstatus;

typedef  struct  _node_  Node;

struct _node_{
int32_t  data;
Node  *next;
};

typedef struct  _queue_  Queue;
struct  _queue_{
Node  *front;
Node  *rear;
uint32_t  count;
};


typedef struct  _queue_result_   QueueResult;
struct  _queue_result_{
int32_t  data;
Qstatus  status;
};


/*Public intefaces*/
Queue    queue_new();
uint8_t  queue_empty(Queue  *q);
Queue*   queue_add(Queue  *q,int32_t  ele,QueueResult *res);
Queue*   queue_delete(Queue  *q,QueueResult  *res);
uint32_t  queue_length(Queue *q);

#endif // LIQUEU_H_INCLUDED
