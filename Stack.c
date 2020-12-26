#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct __stack_node
{
void *data;
struct __stack_node* next;
}StackNode;

typedef struct __STACK__
{
int elementSize;
StackNode * top;
int size;
}STACK;

void initStack(STACK *stack,int elementSize)
{
stack->top=NULL;
stack->elementSize=elementSize;
stack->size=0;
}

int push(STACK *stack,const void* data)
{
if(stack==NULL) return 0;
if(data==NULL) return 0;
StackNode *t;
t=(StackNode*)malloc(sizeof(StackNode));
if(t==NULL) return 0;
t->data=(void*)malloc(stack->elementSize);
if(t->data==NULL)
{
free(t);
return 0;
}
memcpy(t->data,data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
return 1;
}

int pop(STACK *stack,void* data)
{
if(stack==NULL || data==NULL) return 0;
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void*)t->data,stack->elementSize);
free(t->data);
free(t);
return 1;
}

int isEmpty(STACK *stack)
{
if(stack==NULL) return 0;
return stack->size==0;
}


int main()
{
STACK stack;
initStack(&stack,sizeof(int));
int x;
x=10;
push(&stack,(const void*)&x);
x=20;
push(&stack,(const void*)&x);
x=30;
push(&stack,(const void*)&x);
while(!isEmpty(&stack))
{
pop(&stack,(void*)&x);
printf("ok %d\n",x);
}


return 0;
}