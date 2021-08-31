#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	struct node *pre;
	int data;
	struct node *nxt;
}*root;

int main()
{
	int dta;
	printf("Enter a data:");
	scanf("%d",&dta);
	root=(struct node*)malloc(sizeof(struct node));
	root->pre=NULL;
	root->data=dta;
	root->nxt=NULL;
	printf("Entire data is:-> %d",root->data);
}

