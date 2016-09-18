#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
   int data;
   struct Node * next;
}Node;
void addCumulative(Node *head){
	if(head==NULL)
	return;
	while(head->next){
		head->next->data+=head->data;
		head=head->next;
	}
}
void insert(Node **head,int val){
	
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=val;
	p->next=NULL;
	if(*head==NULL)
	{
		*head=p;
		return;
	}
	Node *t=*head;
	while(t->next){
		t=t->next;
	}
	t->next=p;
}
void print(Node *start){
	while(start){
		printf("%d ",start->data);
		start=start->next;
	}
}
void _free(Node **start){
	Node *t=*start;
	while(*start){
		t=*start;
		*start=t->next;
		free(t);
	}
	free( *start);
}
void main(){
	Node *start=NULL;
	insert(&start,2);
	insert(&start,3);
	insert(&start,4);
	insert(&start,5);
	insert(&start,3);
	insert(&start,4);
	insert(&start,5);
	print(start);
	printf("\n");
	addCumulative(start);
	print(start);
 	_free(&start);
}
