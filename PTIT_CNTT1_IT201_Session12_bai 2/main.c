#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node * create_node(int value)
{
    node * newnode= (node *)malloc(sizeof(node));
    if (newnode == NULL) return NULL;
    newnode-> data= value;

    newnode-> next=NULL;
    newnode-> prev=NULL;
    return newnode;

}
void printf_lit(node * head)
{
    printf("NULL->");
    node * current = head;
    while (current!= NULL)
    {
        printf( "%d<->", current->data);
        current=current->next;
    }
    printf("NULL\n");
}
node * add_node(int n)
{
    if (n<=0) return NULL;
    int value;
    printf(" nhap gia tri cho node 1:");
    scanf("%d", &value);

    node *head = create_node(value);
    node * current=head;
    for (int i=2 ;i<= n;i++)
    {
        printf(" nhap gia tri cho node %d:",i);
        scanf("%d", &value);
        node * newnode= create_node(value);
        current->next= newnode;
        newnode->prev=current;
        current=newnode;

    }
    return head;
}
node *data_node(node * head)
{
    node * current = head;
    while (current!=NULL)
    {
        printf(" data: %d", current->data);
        current=current->next;
    }

}
int main(void)
{
    int n;
    do
    {
        printf("nhap so luong node trong danh sach");
        scanf("%d", &n);
    }while (n<=0);
    node * head = add_node(n);
    data_node(head);

    return 0;
}