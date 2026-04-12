#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct edge
{
    int y;
    int weight;
    edge * next;
};
edge * new_edge()
{
    static edge a[400005];
    static int top=0;
    return &a[top++];
}
edge * li[100005];
void inserts(int x,int y,int z)
{
    edge * t=new_edge();
    t->y=y;
    t->weight=z;
    t->next=li[x];
    li[x]=t;
}
void insert_edge(int x,int y,int z)
{
    inserts(x,y,z);
    inserts(y,x,z);
}
priority_queue<pair<long long,int> > q;
long long dist[100005];
int dp[100005];
long long dis[100005];
int dp2[100005];
const int modo=1000000007;
bool vis[100005];
void dijkstra(int s)
{
    q.push(make_pair(0,s));
    memset(dist,-1,sizeof(dist));
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
    dp[s]=1;
    dist[s]=0;
    for (;!q.empty();)
    {
        int x=q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x]=true;
        edge * t;
        for (t=li[x];t!=0;t=t->next)
        {
            if (dist[t->y]==dist[x]+t->weight)
            {
                dp[t->y]=(dp[t->y]+dp[x])%modo;
            }
            if ((dist[t->y]>dist[x]+t->weight)||(dist[t->y]==-1))
            {
                dp[t->y]=dp[x];
                dist[t->y]=dist[x]+t->weight;
                q.push(make_pair(-dist[t->y],t->y));
            }
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int s,t;
    scanf("%d%d",&s,&t);
    s--;
    t--;
    int i;
    for (i=0;i<m;i++)
    {
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        x--;
        y--;
        insert_edge(x,y,d);
    }
    dijkstra(t);
    memcpy(dis,dist,sizeof(dis));
    memcpy(dp2,dp,sizeof(dp2));
    long long val=dis[s];
    dijkstra(s);
    int ans=(long long)dp[t]*dp[t]%modo;
    for (i=0;i<n;i++)
    {
        if (dist[i]+dis[i]!=val) continue;
        if (dist[i]==dis[i])
        {
            ans-=(long long)dp[i]*dp2[i]%modo*dp[i]%modo*dp2[i]%modo;
            ans%=modo;
        }
        edge * t;
        for (t=li[i];t!=0;t=t->next)
        {
            if (dist[t->y]+dis[t->y]!=val) continue;
            if (dist[i]+t->weight!=dist[t->y]) continue;
            if (dist[i]*2>=val) continue;
            if (dist[t->y]*2<=val) continue;
            ans-=(long long)dp[i]*dp2[t->y]%modo*dp[i]%modo*dp2[t->y]%modo;
            ans%=modo;
        }
    }
    ans+=modo;
    ans%=modo;
    printf("%d\n",ans);
    return 0;
} 
