#include<bits/stdc++.h>

using namespace std;

#define mz 1000000007
#define pq priority_queue

struct Node
{
    int no;
    long long d;
    bool friend operator <(Node x1,Node x2)
    {
        return x1.d>x2.d;
    }
}temp;
struct Edge
{
    int u,v;
    long long d;
}es[2000005];
long long dp[2][100005];
long long dis[2][100005];
vector <int> vec[100005];
pq <Node> q;

void dij(int f,int s)
{
    Node now;
    temp.no=s;
    temp.d=0;
    dis[f][s]=0;
    dp[f][s]=1;
    q.push(temp);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(dis[f][now.no]==now.d)
        {
            for(int i=0;i<vec[now.no].size();i++)
            {
                if(es[vec[now.no][i]].d+dis[f][now.no]>dis[f][es[vec[now.no][i]].v])
                    continue;
                if(es[vec[now.no][i]].d+dis[f][now.no]<dis[f][es[vec[now.no][i]].v])
                {
                    temp.d=es[vec[now.no][i]].d+dis[f][now.no];
                    temp.no=es[vec[now.no][i]].v;
                    q.push(temp);
                    dis[f][temp.no]=temp.d;
                    dp[f][temp.no]=dp[f][now.no];
                }
                else
                {
                    dp[f][es[vec[now.no][i]].v]+=dp[f][now.no];
                    dp[f][es[vec[now.no][i]].v]%=mz;
                }
            }
        }
    }
}

int main()
{
    int n,m;
    int s,t;
    long long wtf,gg,tmd;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    for(int i=1;i<=n;i++)
        dis[0][i]=dis[1][i]=200000LL*mz;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%lld",&es[i].u,&es[i].v,&es[i].d);
        es[i].d*=2;
        es[2000000-i].d=es[i].d;
        es[2000000-i].u=es[i].v;
        es[2000000-i].v=es[i].u;
        vec[es[i].u].push_back(i);
        vec[es[i].v].push_back(2000000-i);
    }
    dij(0,s);
    dij(1,t);
    gg=(dp[0][t]*(dp[0][t]-1))%mz;
    wtf=dis[0][t];
    for(int i=1;i<=n;i++)
    {
        if(dis[0][i]==wtf/2 && dis[1][i]==wtf/2)
        {
            tmd=(dp[0][i]*dp[1][i])%mz;
            gg=(gg-(tmd*(tmd-1))%mz+mz)%mz;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(dis[0][es[i].u]<wtf/2 && dis[1][es[i].v]<wtf/2 && dis[0][es[i].u]+es[i].d+dis[1][es[i].v]==wtf)
        {
            tmd=(dp[0][es[i].u]*dp[1][es[i].v])%mz;
            gg=(gg-(tmd*(tmd-1))%mz+mz)%mz;
        }
        if(dis[0][es[i].v]<wtf/2 && dis[1][es[i].u]<wtf/2 && dis[0][es[i].v]+es[i].d+dis[1][es[i].u]==wtf)
        {
            tmd=(dp[0][es[i].v]*dp[1][es[i].u])%mz;
            gg=(gg-(tmd*(tmd-1))%mz+mz)%mz;
        }
    }
    printf("%lld\n",gg);
	return 0;
}
