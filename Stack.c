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

void push(STACK *stack,const void* data)
{
StackNode *t;
t=(StackNode*)malloc(sizeof(StackNode));
t->data=(void*)malloc(stack->elementSize);
memcpy(t->data,data,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}

void pop(STACK *stack,void* data)
{
StackNode *t;
t=stack->top;
stack->top=stack->top->next;
stack->size--;
memcpy(data,(const void*)t->data,stack->elementSize);
free(t->data);
free(t);
}

int isEmpty(STACK *stack)
{
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