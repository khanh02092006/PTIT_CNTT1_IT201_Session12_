#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;
node* createnode(int value)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL) return NULL;
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
node* ceatelite(int n)
{
    if(n==0) return NULL;
    int value;
    printf(" nhap gia tri node 1");
    scanf("%d",&value);
    node *head=createnode(value);
    node *current=head;
    for (int i=2;i<=n;i++)
    {
        printf(" nhap gia tri node %d",i);
        scanf("%d",&value);
        node *newnode=createnode(value);
        current->next=newnode;
        newnode->prev=current;
        current=newnode;

    }
    return head;
}
void printf_lite(node *head)
{

    node *current=head;
    while (current!=NULL)
    {
        printf(" %d<->",current->data);
        current=current->next;

    }
    printf("NULL\n");
}
node* themcuoi(node *head,int value)
{
    node *current=head;
    if (head==NULL)
    {
        return NULL;
    }
    node *newnode=createnode(value);
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=newnode;
    newnode->prev=current;
    return head;
}

int main(void)
{
    int n;
    printf(" nhap so luong danh sach");
    scanf("%d",&n);
    node *head= ceatelite(n);
    int value;
    printf(" nhap gia tri muon them cuoi");
    scanf("%d",&value);
    head=themcuoi(head,value);
    printf_lite(head);

    return 0;
}