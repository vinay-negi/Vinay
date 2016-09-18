#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
void insert(node **root,int val){
	node *p=(node*)malloc(sizeof(node));
	p->data=val;
	p->left=p->right=NULL;
	if(*root==NULL){
		*root=p;
		return;
	}
	node *t=*root;
	while((t->data>val&&t->left)||(t->data<=val&&t->right)){
		if(t->data>val)
			t=t->left;
		else
			t=t->right;
	}
	if(t->data>val)
		t->left=p;
	else
		t->right=p;
}
int print(node *root){
	if(root==NULL)
		return 1;
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
} 
void _free(node **root){
	if(root==NULL||*root==NULL)
	return ;
	_free(&(*root)->left);
	_free(&(*root)->right);
	free(*root);
	*root=NULL;
	root=NULL;			
}
int check(node* root,int data){
	if(root==NULL)return 0;
	if(root->data==data)
	return 1;	
	return check(root->left,data)||
	check(root->right,data);
}
int ancestor(node *root,int data){
	if(root==NULL)return 0;
	 
	if(root->data==data)
	return 1;
	
	if(check(root->left,data)){
		printf("%d ",root->data);
		ancestor(root->left,data);
	}
	else if(check(root->right,data)){
		printf("%d ",root->data);
		ancestor(root->right,data);
	}
}
void find(node *root,int *k){
	if(root==NULL||*k==0)return;
	find(root->right,k);
	(*k)--;
	if(*k==0)
	printf("%d ",root->data);
	find(root->left,k);
}
void main()
{
	int k=8;
	node *root=NULL;
	insert(&root,10);
 	insert(&root,5);
	insert(&root,30);
 	insert(&root,34);
	insert(&root,32);
	insert(&root,7);
	insert(&root,9);
 	insert(&root,8);
 	insert(&root,12);
	insert(&root,40);
	insert(&root,35);
	print(root);
	printf("\n");
	//ancestor(root,35);
	find(root,&k);
  	_free(&root);
 	
}
