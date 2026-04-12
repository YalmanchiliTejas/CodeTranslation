#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
using namespace std;

struct Node
{
    int data,priority;
    Node *l,*r;
};

void rightRotate(Node *&p)
{
    Node *s=p->l;
    p->l=s->r;
    s->r=p;
    p=s;
}

void leftRotate(Node *&p)
{
    Node *s=p->r;
    p->r=s->l;
    s->l=p;
    p=s;
}

void insert_point(Node *&p,int x,int y)
{
    if(p==NULL)
    {
        p=(Node *)malloc(sizeof(Node));
        p->data=x;
        p->priority=y;
        p->l=p->r=NULL;
        return;
    }
    if(x < p->data)
    {
        insert_point(p->l,x,y);
        if(p->priority < p->l->priority)
            rightRotate(p);
    }
    else
    {
        insert_point(p->r,x,y);
        if(p->priority < p->r->priority)
            leftRotate(p);
    }
}

bool find_point(const Node *p,int x)
{
    if(p==NULL)
        return false;
    if(p->data==x)
        return true;
    else if(x<=p->data)
        return find_point(p->l,x);
    else
        return find_point(p->r,x);
}
void delete_assist(Node *&p)
{
    if(p->l==NULL &&p->r==NULL)
        p=NULL;
    else if(p->l==NULL)
        leftRotate(p),delete_assist(p->l);
    else if(p->r==NULL)
        rightRotate(p),delete_assist(p->r);
    else
    {
        if(p->l->priority > p->r->priority)
            rightRotate(p),delete_assist(p->r);
        else
            leftRotate(p),delete_assist(p->l);
    }
}

bool delete_point(Node *&p,int x)
{
    if(p==NULL)
        return false;
    if(p->data==x)
    {
        delete_assist(p);
        return true;
    }
    else if(x<=p->data)
        return delete_point(p->l,x);
    else
        return delete_point(p->r,x);
}

void inorder(Node *p)
{
    if(p!=NULL)
    {
        inorder(p->l);
        printf(" %d",p->data);
        //printf(" %d",p->priority);
        inorder(p->r);
    }
}

void preorder(Node *p)
{
    if(p!=NULL)
    {
        printf(" %d",p->data);
        //printf(" %d",p->priority);
        preorder(p->l);
        preorder(p->r);
    }
}

int main()
{
    int i,m,x,y;
    char st[20];
    Node *tree=NULL;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%s",st);
        switch (st[0])
        {
        case 'i' :
            scanf("%d%d\n",&x,&y);
            insert_point(tree,x,y);
            break;
        case 'f' :
            scanf("%d\n",&x);
            if(find_point(tree,x))
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
            break;
        case 'd' :
            scanf("%d\n",&x);
            delete_point(tree,x);

            break;
        default:
            inorder(tree);
            cout<<endl;
            preorder(tree);
            cout<<endl;
        }
    }
    return 0;
}

