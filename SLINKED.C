#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void create();
void insert_beg();
void insert_pos();
void insert_end();
void delete_beg();
void delete_pos();
void delete_end();
void delete_all();
void search();
void display();
void main()
{
	int ch;
	do
	{
		printf("\n operations on singly linked list \n");
		printf("\n1.create\n2.insert a node at beginning\n3.insert a node at specified node\n4.insert a node at the end\n5.delete a node from the beginning\n6.delete a node from the specified position\n7.delete a node from the end\n8.delete the entire linkedlist\n9.search an element\n10.display the linkedlist\n11.exit\n");
		printf("\n enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				insert_beg();
				break;
			case 3:
				insert_pos();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				delete_beg();
				break;
			case 6:
				delete_pos();
				break;
			case 7:
				delete_end();
				break;
			case 8:
				delete_all();
				break;
			case 9:
				search();
				break;
			case 10:
				display();
				break;
			case 11:
				exit(0);
				break;
			default:
				printf("\n invalid choice\n");
				break;
		}
	}
	while(ch!=11);
}
void create()
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\n memory cannot be allocated\n");
	}
	printf("\n enter the value:\n");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void insert_beg()
{
	struct node *ptr;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("\n overflow\n");
	}
	else
	{
		printf("\n enter the value:\n");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("\n node is inserted\n");
	}
}
void insert_pos()
{
	int i,loc,item;
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n overflow\n");
	}
	else
	{
		printf("\n enter the value:\n");
		scanf("%d",&item);
		ptr->data=item;
		printf("\n enter the location after which you want to insert:");
		scanf("%d",&loc);
		temp=head;
		for(i=0;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\n node can't be inserted");
				return;
			}
		}
		ptr->next=temp->next;
		temp->next=ptr;
		printf("\n node is inserted");
	}
}
void insert_end()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n overflow\n");
	}
	else
	{
		printf("\n enter the value:\n");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			printf("\n node inserted");
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
			printf("\n node inserted\n");
		}
	}
}
void delete_beg()
{
	struct node*ptr;
	if(head==NULL)
	{
		printf("\n list is empty\n");
	}
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		printf("\n node deleted from beginning");
	}
}
void delete_pos()
{
	struct node *ptr,*ptr1;
	int loc,i;
	printf("\n enter location of node after which deletion is to be performed:");
	scanf("%d",&loc);
	ptr=head;
	for(i=0;i<loc;i++)
	{
		ptr1=ptr;
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("\n can't delete\n");
			return;
		}
	}
	ptr1->next=ptr->next;
	free(ptr);
	printf("\n deleted node %d",loc+1);
}
void delete_end()
{
	struct node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("\n list is empty\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\n only node of the list is deleted\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=NULL;
		free(ptr);
		printf("\n deleted node from the list\n");
	}
}
void delete_all()
{
	struct node *temp;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	printf("\n successfully deleted entire nodes of linked list\n");
}
void search()
{
	struct node *ptr;
	int item,i=0,flag=0;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n empty list \n");
	}
	else
	{
		printf("\n enter item to be searched :\n");
		scanf("%d",&item);
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				printf("\n item found at location %d",i+1);
				flag=0;
			}
			else
			{
				flag=1;
			}
			i++;
			ptr=ptr->next;
		}
		if(flag==1)
		{
			printf("\n item not found\n");
		}
	}
}
void display()
{
	struct node *ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n no data items found so nothing to print\n");
	}
	else
	{
		printf("\n printing values \n");
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
