#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
#define DEB(x) cout << #x << " : " << x << '\n'
#define ALL(x) x.begin(), x.end()
#define SZ(x) x.size()
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
typedef long long ll;

#define MXN 100005
int N,M,S,T;
vector<pil> G[MXN];
ll dis[MXN];
ll W[2][MXN];
bool onsp[MXN];
bool vis[MXN];
ll Ans;

void dfs1(int u)
{
    vis[u]=true;
    if(u==T)
    {
        onsp[u]=true;
        W[0][u]=1;
        return;
    }
    for( pil e : G[u] )
    {
        int v = e.f;
        ll d = e.s;
        if( dis[u]+d==dis[v] )
        {
            if( !vis[v] )dfs1(v);

            if( onsp[v] )
            {
                onsp[u]=true;
                W[0][u]=(W[0][u]+W[0][v])%MOD;
            }
        }
    }
}

void dfs2(int u)
{
    vis[u]=true;
    if(u==S)
    {
        W[1][u]=1;
        return;
    }
    for( pil e : G[u] )
    {
        int v = e.f;
        ll d = e.s;
        if( dis[u]-d==dis[v] && onsp[v] )
        {
            if( !vis[v] )dfs2(v);
            W[1][u]=(W[1][u]+W[1][v])%MOD;
        }
    }
}

void deduce(int u)
{
    vis[u]=true;
    if(u==T)return;
    for( pil e : G[u] )
    {
        int v = e.f;
        ll d = e.s;
        ll disv = dis[T]-dis[v];
        if( !onsp[v] || vis[v] || dis[u]+d!=dis[v] )continue;
        //cout<<u<<" : "<<dis[u]<<" // "<<v<<" : "<<disv<<'\n';
        if( dis[u]+d==disv )
        {
            vis[v]=true;
            ll de = W[0][v]*W[1][v]%MOD;
            de=(de*W[0][v]%MOD)*W[1][v]%MOD;
            Ans=(MOD+(Ans-de)%MOD)%MOD;
        }
        else if( dis[u]+d>disv )
        {
            ll de = W[0][v]*W[1][u]%MOD;
            de=(de*W[0][v]%MOD)*W[1][u]%MOD;
            Ans=(MOD+(Ans-de)%MOD)%MOD;
        }
        else deduce(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>S>>T;
    int u,v;
    ll d;
    FOR(i,1,M)
    {
        cin>>u>>v>>d;
        G[u].pb(mkp(v,d));
        G[v].pb(mkp(u,d));
    }
    ll mxd = (1LL<<60);
    FOR(i,1,N)dis[i]=mxd;
    dis[S]=0;
    priority_queue< pli, vector<pli>, greater<pli> > pq;
    pq.push( mkp(0,S) );

    while(!pq.empty())
    {
        pli now = pq.top();
        pq.pop();
        int u = now.s;
        ll d = now.f;
        if( dis[u]!=d )continue;
        if( u==T )break;
        for( pil e : G[u] )
        {
            int vi = e.f;
            ll di = e.s;
            if( d+di<dis[vi] )
            {
                dis[vi]=d+di;
                pq.push(mkp(dis[vi],vi));
            }
        }
    }
    dfs1(S);
    CL(vis);
    dfs2(T);

    //Ans=all comb - forbidden ones
    ll Al = W[0][S];
    Ans = Al*Al%MOD;
    CL(vis);
    deduce(S);
    cout<<Ans<<'\n';

    return 0;
}
