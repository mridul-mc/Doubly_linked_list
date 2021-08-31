#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int create_list(int n);
int display_list();
struct node
{
	struct node *pre;
	int data;
	struct node *nxt;
}*root;
int main()
{
	int n;
	printf("How many node you want to create:");
	scanf("%d",&n);
	create_list(n);
	display_list();
}
int create_list(int n)
{
	int i;
	struct node *fun_node,*tmp;
	root=(struct node*)malloc(sizeof(struct node));
	if(root==NULL)
	{
		printf("Memory can't allocate");
	}
	else
	{
		printf("Enter data for 1 node:");
		scanf("%d",&root->data);
		root->pre=NULL;
		root->nxt=NULL;
		tmp=root;
		for(i=2;i<=n;i++)
		{
			fun_node=(struct node*)malloc(sizeof(struct node));
			if(fun_node==NULL)
			{
				printf("Memory can't allocate");
			}
			else
			{
				printf("Enter data for %d node:",i);
				scanf("%d",&fun_node->data);
				fun_node->pre = tmp;
				fun_node->nxt = NULL;
				tmp->nxt = fun_node;
				tmp=fun_node;
			}
		}
	}
}
int display_list()
{
	struct node *tmp=root;
	if(root==NULL)
	{
		printf("memory can't allocate");
	}
	else
	{
		while(tmp!=NULL)
		{
			printf("Data:-> :%d\n",tmp->data);
			tmp=tmp->nxt;
		}
	}
}
