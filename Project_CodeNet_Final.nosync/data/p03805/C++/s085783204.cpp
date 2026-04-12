#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define P push
#define R return
#define C continue
#define MEM(dp,i) memset(dp,i,sizeof(dp))
#define SI size()
#define F first
#define S second
#define B begin()
#define E end()
#define W while
using namespace std;
long long MOD=1e9+7;
long long INF=1e16+7;
ll n,m,dp[11][(1<<10)];
vector<ll> adj[10];
ll DP(ll x,ll mask){
    if(mask==((1<<n)-1))R 1;
    ll &ret=dp[x][mask];
    if(ret!=-1)R ret;
    ret=0;
    for(int i=0;i<adj[x].SI;i++){
        ll node=adj[x][i];
        if(mask&(1<<node))C;
        ret+=DP(node,mask+(1<<node));
    }
    R ret;
}
int main()
{
    MEM(dp,-1);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout<<DP(0,1);
    return 0;
}
