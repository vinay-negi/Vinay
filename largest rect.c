#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct node{
	int data;
	int index;
	struct node *next;
}node;
int inx=0;int max=0,maxinx=0;
void insert(node **top,int h){

	node *p=(node*)malloc(sizeof(node));
	p->data=h;
	p->index=inx++;
	p->next=*top;
	*top=p;
}
void pop(node **top ){
	if(*top==NULL)return;
	int t=0;
	if((*top)->next)
		t=(inx-1-(*top)->next->index)*(*top)->data;
	else
		t=(*top)->data*inx;
//	printf("%d %d",t, (*top)->next->index);getch();
// 	printf("%d",t);
	if(t>max)
		max=t;
	*top=(*top)->next;
	
}
void calc(node **top,int h){
	
	if(*top==NULL||(*top)->data<= h)
	{
		insert(top,h);
		return;
	}
	else
	{
	 	while(*top&&h<=(*top)->data){
			pop(top);
	 	}
	 	insert(top,h);
	}
	
}
int main() {
	node* top=NULL;
	int n,h;
	scanf("%d",&n);
	while(n){
		n--;
		scanf("%d",&h);
		calc(&top,h);
	}  
	while( top){
		pop(&top);
	}
	printf("%d \n",max);
 

	
    return 0;
}

