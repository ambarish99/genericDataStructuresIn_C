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


typedef struct lbub
{
int lb;
int ub;
}LBUB;


void merge(int arr[],int lb1,int ub2)
{
int ub1,lb2,e,f,g;
ub1=(lb1+ub2)/2;
lb2=ub1+1;
int *temp;
temp=(int*)malloc(sizeof(int)*(ub2-lb1+1));
f=lb1;
g=lb2;
for(e=0;e<ub2-lb1+1 && f<=ub1 && g<=ub2;)
{
 if(arr[f]<arr[g])
 {
   temp[e]=arr[f];
   f++;
   e++;
 } 
 else
 {
   temp[e]=arr[g];
   g++;
   e++;   
 }
}

while(f<=ub1)
{
temp[e]=arr[f];
e++;
f++;
}
while(g<=ub2)
{
temp[e]=arr[g];
e++;
g++;
}
for(e=0,f=lb1;e<ub2-lb1+1;e++,f++) arr[f]=temp[e];
free(temp);
}


void mergeSort(int arr[],int lb, int ub)
{
STACK s1,s2;
int mid,ub1,lb1,lb2,ub2;
LBUB *lbub=(LBUB*)malloc(sizeof(LBUB)); 
LBUB *mid1,*mid2;
initStack(&s1,sizeof(LBUB));
initStack(&s2,sizeof(LBUB));
lbub->lb=lb;
lbub->ub=ub;
push(&s1,(const void*)lbub);

while(!isEmpty(&s1))
{
pop(&s1,(void*)lbub);
push(&s2,(const void*)lbub);
mid=(lbub->lb+lbub->ub)/2;

if(lbub->lb<mid) 
{
mid1=(LBUB*)malloc(sizeof(LBUB));
mid1->lb=lbub->lb;
mid1->ub=mid;
push(&s1,mid1);
free(mid1);
}
if(mid+1<lbub->ub)
{
mid2=(LBUB*)malloc(sizeof(LBUB));
mid2->lb=mid+1;
mid2->ub=lbub->ub;
push(&s1,mid2);
free(mid2);
}
}
int e,f,g;
while(!isEmpty(&s2))
{
pop(&s2,(void*)lbub);
lb1=lbub->lb;
ub2=lbub->ub;
merge(arr,lb1,ub2);
}
}



int main()
{
int i,j,*arr,n;

printf("Req=");
scanf("%d",&n);

arr=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++) scanf("%d",&arr[i]);

mergeSort(arr,0,n-1);
printf("--------------------------\n");
for(i=0;i<n;i++) printf("%d\n",arr[i]);

return 0;
}