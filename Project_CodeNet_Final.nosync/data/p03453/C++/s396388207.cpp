#include <bits/stdc++.h>
#define MN 100100
#define MOD 1000000007
typedef long long int ll;
#define pb push_back
#define mp make_pair
using namespace std;
struct Edge{
    int u,v;
   ll d;
    Edge(int u,int v,ll d):u(u),v(v),d(d){}
};
int n,m,s,t;
const ll INF = 1e17;
vector<pair<int,ll> > adj[MN];
vector<Edge> edges;
ll d1[MN],d2[MN],dp1[MN],dp2[MN];
bool check[MN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v;
        ll d;
        cin >> u >> v >> d;
        adj[u].pb(mp(v,d));
        adj[v].pb(mp(u,d));
        edges.pb(Edge(u,v,d));
    }
    for(int i=1;i<=n;i++) d1[i] = INF;
    for(int i=1;i<=n;i++) d2[i] = INF;
    priority_queue<pair<ll,int> > q;
    d1[s] = 0;
    q.push(mp(0,s));
    while(!q.empty()){
        pair<ll,int> p = q.top();
        q.pop();
        int x = p.second;
        if(check[x]) continue;
        check[x] = true;
        for(int i=0;i<adj[x].size();i++){
            int nxt = adj[x][i].first;
            if(d1[nxt]>(d1[x]+adj[x][i].second)){
                d1[nxt] = d1[x]+adj[x][i].second;
                q.push(mp(-d1[nxt],nxt));
            }
        }
    }
    d2[t] = 0;
    for(int i=1;i<=n;i++) check[i] = false;
    q.push(mp(0,t));
     while(!q.empty()){
        pair<ll,int> p = q.top();
        q.pop();
        int x = p.second;
        if(check[x]) continue;
        check[x] = true;
        for(int i=0;i<adj[x].size();i++){
            int nxt = adj[x][i].first;
            if(d2[nxt]>(d2[x]+adj[x][i].second)){
                d2[nxt] = d2[x]+adj[x][i].second;
                q.push(mp(-d2[nxt],nxt));
            }
        }
    }
    dp1[s] = 1;
    for(int i=1;i<=n;i++) q.push(mp(-d1[i],i));
    while(!q.empty()){
        pair<ll,int> p = q.top();
        q.pop();
        int x = p.second;
        for(int i=0;i<adj[x].size();i++){
            int nxt = adj[x][i].first;
            if((d1[x]+adj[x][i].second)==d1[nxt]) dp1[nxt] = (dp1[x]+dp1[nxt])%MOD;
        }
    }
    dp2[t] = 1;
    for(int i=1;i<=n;i++) q.push(mp(-d2[i],i));
    while(!q.empty()){
        pair<ll,int> p = q.top();
        q.pop();
        int x = p.second;
        for(int i=0;i<adj[x].size();i++){
            int nxt = adj[x][i].first;
            if((d2[x]+adj[x][i].second)==d2[nxt]) dp2[nxt] = (dp2[x]+dp2[nxt])%MOD;
        }
    }
    ll ans = (dp1[t]*dp1[t])%MOD;
    for(int i=1;i<=n;i++){
        if((2*d1[i])==d1[t] && d1[i]==d2[i]){
            ans = (ans+MOD-((((((dp1[i]*dp1[i])%MOD)*dp2[i])%MOD)*dp2[i])%MOD))%MOD;
        }
    }
    for(int i=0;i<m;i++){
            int x = edges[i].u;
            int y = edges[i].v;
        if((2*d1[x])<(d1[t]) && (2*d2[y])<d1[t] && (d1[x]+d2[y]+edges[i].d)==d1[t]){
                ans = (ans+MOD-((((((dp1[x]*dp1[x])%MOD)*dp2[y])%MOD)*dp2[y])%MOD))%MOD;

        }
        if((2*d1[y])<(d1[t]) && (2*d2[x])<d1[t] && (d1[y]+d2[x]+edges[i].d)==d1[t]){
                ans = (ans+MOD-((((((dp1[y]*dp1[y])%MOD)*dp2[x])%MOD)*dp2[x])%MOD))%MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}
    