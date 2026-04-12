#include<bits/stdc++.h>
using namespace std;
#define maxn 100100
struct Edge
{
    int to,next;
}edge[maxn<<1];
int head[maxn],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int siz[maxn];
bool ok=true;
int n;
void dfs(int u,int pre)
{
    siz[u]=1;
    int cnt=0;
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==pre) continue;
        dfs(v,u);
        if(siz[v]&1) ++cnt;
        siz[u]+=siz[v];
    }
    if((n-siz[u])&1) ++cnt;
    if(cnt>1) ok=false;
}
int main()
{
    scanf("%d",&n);
    init();
    for(int i=1;i<n;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,-1);
    if(ok) puts("Second");
    else puts("First");
    return 0;
}
