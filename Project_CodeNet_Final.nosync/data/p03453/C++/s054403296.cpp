#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=4e5+5,mod=1e9+7;
ll dp[2][N],dis[2][N];
int n,m,s,t,a[N],b[N],c[N],tot,head[N],nex[N],to[N],wi[N];
void add(int u,int v,int w){to[++tot]=v;nex[tot]=head[u];head[u]=tot;wi[tot]=w;}
struct node
{
    int x;ll v;
    node(int x=0,ll v=0):x(x),v(v){}
    bool operator<(const node&o)const
    {
        return v>o.v;
    }
};
bool vis[N];
void solve(int u,int p)
{
    priority_queue<node>q;
    memset(vis,false,sizeof(vis));
    q.push(node(u,0));
    dis[p][u]=0;dp[p][u]=1;
    while(!q.empty())
    {
        int u=q.top().x;q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i;i=nex[i])
        {
            int v=to[i];
            if(dis[p][v]>dis[p][u]+wi[i])
            {
                dis[p][v]=dis[p][u]+wi[i];
                dp[p][v]=dp[p][u];
                q.push(node(v,dis[p][v]));
            }
            else if(dis[p][v]==dis[p][u]+wi[i])
                (dp[p][v]+=dp[p][u])%=mod;
        }
    }
}
ll solve(int x,int y,int c)
{
    if(dis[0][x]+dis[1][y]+c>dis[0][t]) return 0;
    ll m1,m2;
    if(dis[0][t]&1) m1=m2=dis[0][t]/2+1;
    else m1=dis[0][t]/2,m2=m1+1;
    if(m1>dis[0][x]&&m2<=dis[0][x]+c)
        return dp[0][x]*dp[1][y]%mod;
    return 0;
}
ll solve(int x)
{
    if(dis[0][x]==dis[0][t]/2&&dis[1][x]==dis[0][t]/2) return dp[0][x]*dp[1][x]%mod;
    return 0;
}
int main()
{
    memset(dis,inf,sizeof(dis));
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        add(a[i],b[i],c[i]);add(b[i],a[i],c[i]);
    }
    solve(s,0);
    solve(t,1);
    ll ans=dp[0][t]*(dp[0][t]-1)%mod;
    for(int i=1;i<=m;i++)
    {
        ll res=solve(a[i],b[i],c[i]);
        res=res*(res-1)%mod;
        (ans-=res)%=mod;
        res=solve(b[i],a[i],c[i]);
        res=res*(res-1)%mod;
        (ans-=res)%=mod;
    }
    if(dis[0][t]%2==0)
    for(int i=1;i<=n;i++)
    {
        ll res=solve(i);
        res=res*(res-1)%mod;
        (ans-=res)%=mod;
    }
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
}
