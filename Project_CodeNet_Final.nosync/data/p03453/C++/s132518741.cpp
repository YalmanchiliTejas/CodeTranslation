#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007ll;
const int N = 100100;

int n , m ;
int s , t ;
bool vis[N] , in[N];
ll  dis[2][N] , mem[2][N];
vector<pair<int,ll>>adj[N];
priority_queue<pair<ll,int>>Q;

void dij(int _,int u){
dis[_][u]=0ll;
Q.push({0ll,u});
while( !Q.empty() ){
    int u = Q.top().second;
    Q.pop();

    for(auto p:adj[u]){
        int v = p.first;
        ll d = p.second;
        if( dis[_][v] > dis[_][u]+d ){
            dis[_][v] = dis[_][u]+d;
            Q.push( {-  dis[_][v],v} );
        }
    }
}
}

void dfs(int u){
vis[u]=in[u]=1;
if( u == s )return;
for(auto p:adj[u]){
    int v = p.first;
    ll d = p.second;
    if( vis[v] )continue;
    if( dis[0][v] +d == dis[0][u] )
        dfs(v);
}
}

ll dp(int _,int u){
if( _ && u==s)return 1ll;
if(!_ && u==t)return 1ll;

ll &ret=mem[_][u];
if( ret !=-1 )return ret;
ret=0;
for(auto p:adj[u]){
    int v = p.first;
    ll d = p.second;
    if( in[v] )
        if( dis[_][u]+d == dis[_][v] )
        ret=( ret + dp(_,v) )%mod;
}
return ret;
}

int main(){

scanf("%d %d",&n,&m);
scanf("%d %d",&s,&t);

while( m-- ){
    int u,v;ll d;
    scanf("%d %d %lld",&u,&v,&d);
    adj[u].push_back({v,d});
    adj[v].push_back({u,d});
}

for(int i=0;i<2;i++)
    for(int j=1;j<=n;j++)
        dis[i][j]=1ll<<60;

dij(0,s);
dij(1,t);
dfs(t);
memset(mem,-1,sizeof mem);
ll ans = dp(0,s) * dp(1,t) %mod;

//printf("%lld\n",ans);

for(int i=1;i<=n;i++)
    if( in[i] && dis[0][i]==dis[1][i] ){
        ans = ( ans - dp(0,i)*dp(1,i)%mod*dp(1,i)%mod*dp(0,i)%mod + mod )%mod;
    }

//printf("%lld\n",ans);
ll mx = dis[0][t];
for(int i=1;i<=n;i++)
for(auto p:adj[i]){
    int j = p.first;
    ll d = p.second;
    if( in[i] && in[j] )
    if( dis[0][i]+d == dis[0][j]  )
    if( dis[1][i]   == dis[1][j]+d)
    if( dis[0][i] < mx/2 )
    if( dis[0][j] > mx/2 )
    if( dis[1][j] < mx/2 )
    if( dis[1][i] > mx/2 )
    if( dis[0][i]+d+dis[1][j]==mx  )
        ans = ( ans - dp(1,i)*dp(0,j)%mod*dp(1,i)%mod*dp(0,j)%mod + mod )%mod;

}
printf("%lld\n",ans);
return 0;
}
