#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int create_list(int n);
int display_list();
int insert_front();
int insert_end();
int delete_first();
int delete_last(int);
int search_node(int);
int revers_list();
int display_list();
struct node
{
	struct node *pre;
	int data;
	struct node *nxt;
}*root,*tmp;
int main()
{
	int n,c,se;
	printf("How many node you want to create:");
	scanf("%d",&n);
	create_list(n);
	printf(" 1.Insert at front\n 2.Insert at last\n 3.Delete first node\n 4.Delete last node\n 5.Search a number\n 6.Reverse the list\n Enter your choise:");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			insert_front();
			display_list();
			break;
		case 2:
			insert_end();
			display_list();
			break;
		case 3:
			delete_first();
			display_list();
			break;
		case 4:
			delete_last(n);
			display_list();
			break;
		case 5:
			printf("Enter your searching element:");
			scanf("%d",&se);
			search_node(se);
			break;
		case 6:
			revers_list();
			break;
		default:
			printf("Wrong input");
	}
}
int create_list(int n)
{
	int i;
	struct node *fun_node;
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
	struct node *temp=root;
	if(root==NULL)
	{
		printf("memory can't allocate");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("Node data are:%d\n",temp->data);
			temp=temp->nxt;
		}
	}
}
int insert_front()
{
	struct node *fun_node;
		fun_node=(struct node*)malloc(sizeof(struct node));
		printf("Enter data for first node:");
		scanf("%d",&fun_node->data);
		fun_node->pre=NULL;
		fun_node->nxt=root;
		root->pre=fun_node;
		root=fun_node;
}
int insert_end()
{
	struct node *fun_node;
		fun_node=(struct node*)malloc(sizeof(struct node));
		printf("Enter data for last node:");
		scanf("%d",&fun_node->data);
		fun_node->nxt=NULL;
		tmp->nxt=fun_node;
		fun_node->pre=tmp;
}
int delete_first()
{
	struct node *p=root;
	root=root->nxt;
	root->pre=NULL;
	p->nxt=NULL;
	free(p);
}
int delete_last(int len)
{
	int i=1;
	struct node *p=root,*q;
	while(i<len-1)
	{
		p=p->nxt;
		i++;
	}
	q=p->nxt; //collect last node
	q->pre=NULL; //break last node to previous
	p->nxt=NULL; //break previous node from last node
	free(q); // free last node
}
int search_node(int se)
{
	int i=0,flag=0;
	struct node *temp=root;
	if(root==NULL)
	{
		printf("memory can't allocate");
	}
	else
	{
		while(temp!=NULL)
		{
			i++;
			if(temp->data==se)
			{
				printf("Found at %d position",i);
				flag=1;
				exit(0);
			}
			else
			{
				temp=temp->nxt;
			}
		}
		if(flag==0)
		{
			printf("Not found");
		}
	}
}
int revers_list()
{
	struct node *temp=tmp;
		while(temp!=NULL)
		{
			printf("Node data are:%d\n",temp->data);
			temp=temp->pre;
		}
}
