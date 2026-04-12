#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int key,p;
    node *L,*R;
    node(int K=0,int P=0)
    {
        key=K;p=P;
        L=R=NULL;
    }
};

node *root=NULL;

node* RR(node *t)
{
    node *s=t->L;
    t->L=s->R;
    s->R=t;
    return s;
}

node* LR(node *t)
{
    node *s=t->R;
    t->R=s->L;
    s->L=t;
    return s;
}

node* Insert(node *t,int K,int P)
{
    if(t==NULL)
    {
        node *p=new node(K,P);
        return p;
    }else if(K==t->key)
    {
        return t;
    }

    if(K<t->key)
    {
        t->L=Insert(t->L,K,P);
        if(t->p<t->L->p)
        {
            t=RR(t);
        }
    }else
    {
        t->R=Insert(t->R,K,P);
        if(t->p<t->R->p)
        {
            t=LR(t);
        }
    }

    return t;
}

node* _Delete(node *,int);
node* Delete(node *t,int K)
{
    if(t==NULL)
    {
        return NULL;
    }else if(K<t->key)
    {
        t->L=Delete(t->L,K);
    }else if(K>t->key)
    {
        t->R=Delete(t->R,K);
    }else
    {
        return _Delete(t,K);
    }
    return t;
}

node* _Delete(node *t,int K)
{
    if(t->L==NULL&&t->R==NULL)
    {
        return NULL;
    }else if(t->L==NULL)
    {
        t=LR(t);
    }else if(t->R==NULL)
    {
        t=RR(t);
    }else
    {
        if(t->L->p>t->R->p)
        {
            t=RR(t);
        }else
        {
            t=LR(t);
        }
    }
    return Delete(t,K);
}

void pre(node *t)
{
    if(t==NULL)
    {
        return;
    }
    printf(" %d",t->key);
    pre(t->L);
    pre(t->R);
}

void in(node *t)
{
    if(t==NULL)
    {
        return;
    }
    in(t->L);
    printf(" %d",t->key);
    in(t->R);
}

node* Find(node *t,int K)
{
    if(t==NULL)
    {
        return NULL;
    }else if(K<t->key)
    {
        return Find(t->L,K);
    }else if(K>t->key)
    {
        return Find(t->R,K);
    }else
    {
        return t;
    }
}

void ins()
{
    int a,b;
    cin>>a>>b;
    root=Insert(root,a,b);
}

void fnd()
{
    int a;
    cin>>a;
    if(Find(root,a))
    {
        cout<<"yes"<<endl;
    }else
    {
        cout<<"no"<<endl;
    }
}

void del()
{
    int a;
    cin>>a;
    root=Delete(root,a);
}

void print()
{
    in(root);cout<<endl;
    pre(root);cout<<endl;
}

int main()
{
    int n;

    cin>>n;

    map<string,int> mp;
    mp["insert"]=1;
    mp["find"]=2;
    mp["delete"]=3;

    while(n--)
    {
        string s;
        cin>>s;

        switch(mp[s])
        {
            case 1:ins();break;
            case 2:fnd();break;
            case 3:del();break;
            default:print();
        }
    }


    return 0;
}

