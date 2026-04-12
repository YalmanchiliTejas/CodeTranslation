#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<string>
using namespace std;

#define MAXN 100010

struct edge
{
    int to,next;
}edg[MAXN];
int head[MAXN];
bool vis[10];
int cnt,ans;
void add(int u,int v)
{
    edg[cnt].to=v;
    edg[cnt].next=head[u];
    head[u]=cnt++;
}
int n,m;
void dfs(int u,int num)
{
    if(num==n)
    {
        ans++;
        return ;
    }
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edg[i].next)
    {
        int v=edg[i].to;
        if(!vis[v])
        {
            dfs(v,num+1);
            vis[v]=0;
        }
    }
}
int main()
{
    cnt=0;
    ans=0;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}
