#include<stdlib.h>
#include<stdio.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;
int main()
{
	int choice;
	while(1)
	{
		printf("\n menu\n");
		printf("\n1.create\n");
		printf("\n2.display\n");
		printf("\n3.insert at beginning\n");
		printf("\n4.insert at end\n");
		printf("\n5.insert at position\n");
		printf("\n6.delete from beginning\n");
		printf("\n7.delete from end\n");
		printf("\n8.delete from position\n");
		printf("\n9.exit\n");
		printf("\n*****************\n");
		printf("\n enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insert_begin();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				insert_pos();
				break;
			case 6:
				delete_begin();
				break;
			case 7:
				delete_end();
				break;
			case 8:
				delete_pos();
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("\n wrong choice \n");
				break;
		}
	}
}
void create()
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\n out of memory space\n");
		exit(0);
	}
	printf("\n enter value for the node :\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("\n list is empty\n");
		return;
	}
	else
	{
		ptr=start;
		printf("\n the list elements are:\n");
		while(ptr!=NULL)
		{
			printf("%d",ptr->info);
			ptr=ptr->next;
		}
	}
}
void insert_begin()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\n out of memory space\n");
		return;
	}
	printf("\n enter value for node :\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}
void insert_end()
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\n out of memory space\n");
		return;
	}
	printf("\n enter value for node :\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void insert_pos()
{
	struct node *ptr,*temp;
	int i,pos;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\n out of memory space\n");
		return;
	}
	printf("\n enter position for new node to be inserted:\n");
	scanf("%d",&pos);
	printf("\n enter value for node:\n");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(pos==0)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		for(i=0,ptr=start;i<pos-1;i++)
		{
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("\n position not found:handle with care\n");
			return;
		}
	}
	temp->next=ptr->next;
	ptr->next=temp;
}
void delete_begin()
{
	struct node *ptr;
	if(ptr==NULL)
	{
		printf("\n list is empty\n");
		return;
	}
	else
	{
		ptr=start;
		start=start->next;
		printf("\n deleted element is : %d",ptr->info);
		free(ptr);
	}
}
void delete_end()
{
	struct node *temp,*ptr;
	if(start==NULL)
	{
		printf("\n list is empty\n");
		exit(0);
	}
	else if(start->next==NULL)
	{
		ptr=start;
		start=NULL;
		printf("\n the deleted element is %d",ptr->info);
		free(ptr);
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		printf("\n the deleted element is %d",ptr->info);
		free(ptr);
	}
}
void delete_pos()
{
	int i,pos;
	struct node *temp,*ptr;
	if(start==NULL)
	{
		printf("\n the list is empty\n");
		exit(0);
	}
	else
	{
		printf("\n enter the position of the node to be deleted:\n");
		scanf("%d",&pos);
		if(pos==0)
		{
			ptr=start;
			start=start->next;
			printf("\n the deleted element is %d",ptr->info);
			free(ptr);
		}
		else
		{
			ptr=start;
			for(i=0;i<pos;i++)
			{
				temp=ptr;
				ptr=ptr->next;
			}
			if(ptr==NULL)
			{
				printf("\n position not found\n");
				return;
			}
		}
		temp->next=ptr->next;
		printf("\n the deleted element is :%d",ptr->info);
		free(ptr);
	}
}
