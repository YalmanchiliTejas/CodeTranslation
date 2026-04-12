#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
using ll = long long;
ll n, m;
ll ans = 0;
void dfs(vector<vector<ll>>& graph, ll v, vector<ll> visited){
    visited.push_back(v);
    if(visited.size()==n){
        ans++;
        return;
    }
    for(auto next:graph[v]){
        bool flag = false;
        for(auto i:visited){
            if(i==next)flag = true;
        }
            if(flag)continue;
        dfs(graph, next, visited);
    }
}
void solve(){
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m;i++){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<ll> visited;
    dfs(adj, 0, visited);
    cout << ans << endl;
}
int main()
{
    solve();
}
