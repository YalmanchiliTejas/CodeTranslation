#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
vector< pair<ll,ll> > adj[N];
ll n,m,s,t,dp[N][2],D[N][2];
priority_queue< pair<ll,ll> > pq;
void SSSP(ll s,ll w){
    D[s][w]=0;
    dp[s][w]=1;
    pq.push({0,s});
    while(!pq.empty()){
        ll v = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
        if(d>D[v][w])continue;
        for(auto &u:adj[v]){
            if(D[u.first][w] > D[v][w] + u.second){
                dp[u.first][w] = 0;
                D[u.first][w] = D[v][w] + u.second;
                pq.push({-D[u.first][w] , u.first});
            }

            if(D[u.first][w] == D[v][w] + u.second){
                dp[u.first][w]+=dp[v][w];
                if(dp[u.first][w]>=mod)dp[u.first][w]-=mod;
            }
        }
    }
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>s>>t;
    for(ll i=1;i<=m;i++){
        ll u,v,d;cin>>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    memset(D,0x3f,sizeof(D));
    SSSP(s,0);
    SSSP(t,1);

    ll ans = dp[t][0]*dp[t][0];
    ans%=mod;


    for(ll i=1;i<=n;i++){
        if(D[i][0]*2==D[t][0] && D[i][1]*2==D[t][0])
            ans = (ans - dp[i][0]*dp[i][1]%mod*dp[i][0]%mod*dp[i][1]%mod + mod)%mod;
    }

    for(ll i=1;i<=n;i++){
        for(auto &u:adj[i]){
            if(D[i][0] + u.second + D[u.first][1] == D[t][0] && D[i][0]*2<D[t][0] && D[u.first][1]*2<D[t][0] )
                ans = (ans - dp[i][0]*dp[u.first][1]%mod*dp[i][0]%mod*dp[u.first][1]%mod + mod)%mod;
        }
    }

    cout<<ans;
}