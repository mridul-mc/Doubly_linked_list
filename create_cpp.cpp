#include<iostream>
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
	cout<<"Enter a data:";
	cin>>dta;
	root=(struct node*)malloc(sizeof(struct node));
	root->pre=NULL;
	root->data=dta;
	root->nxt=NULL;
	cout<<"Entire data is:->"<<root->data;
}

