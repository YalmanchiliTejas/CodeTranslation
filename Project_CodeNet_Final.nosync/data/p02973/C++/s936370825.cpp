#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
    int val,si,tot,fa,ch[2];
}t[N];
int tot,root;
void update(int x)
{
    if(x==0) return;
    t[x].si=t[t[x].ch[0]].si+t[t[x].ch[1]].si+t[x].tot;
}
void Rotate(int x)
{
    int y=t[x].fa,z=t[y].fa,k=t[y].ch[1]==x;
    t[y].ch[k]=t[x].ch[k^1];
    t[t[x].ch[k^1]].fa=y;
    t[x].ch[k^1]=y;
    t[y].fa=x;
    t[x].fa=z;
    t[z].ch[t[z].ch[1]==y]=x;
    update(y);update(x);update(z);
}
void splay(int x,int s)
{
    while(t[x].fa!=s)
    {
        int y=t[x].fa,z=t[y].fa;
        if(z!=s) (t[y].ch[1]==x)^(t[z].ch[1]==y)?Rotate(x):Rotate(y);
        Rotate(x);
    }
    if(s==0) root=x;
}
void Insert(int x)
{
    int u=root,fa=0;
    while(u&&t[u].val!=x)
        fa=u,u=t[u].ch[x>t[u].val];
    if(u) t[u].tot++;
    else
    {
        u=++tot;
        t[u].val=x;
        t[u].si=t[u].tot=1;
        t[u].fa=fa;
        if(fa) t[fa].ch[x>t[fa].val]=u;
        t[u].ch[0]=t[u].ch[1]=0;
    }
    update(u);
    splay(u,0);
}
void Find(int x)
{
    int u=root;
    if(!u) return;
    while(t[u].val!=x&&t[u].ch[x>t[u].val])
        u=t[u].ch[x>t[u].val];
    splay(u,0);
}
int Next(int x,int f)
{
    Find(x);
    int u=root;
    if(t[u].val<x&&!f||t[u].val>x&&f) return u;
    u=t[u].ch[f];
    while(t[u].ch[f^1]) u=t[u].ch[f^1];
    return u;
}
void Delete(int x)
{
    int pre=Next(x,0),bk=Next(x,1);
    splay(pre,0);splay(bk,pre);
    int u=t[bk].ch[0];
    if(!u) return;
    if(t[u].tot>1) t[u].tot--,splay(u,0);
    else
        t[bk].ch[0]=0,update(bk);
}
int main()
{
    Insert(-1);Insert(1e9+1);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x;scanf("%d",&x);
        int u=Next(x,0);
        if(t[u].val==-1) Insert(x);
        else
        {
            Delete(t[u].val);
            Insert(x);
        }
    }
    printf("%d\n",t[root].si-2);
}
