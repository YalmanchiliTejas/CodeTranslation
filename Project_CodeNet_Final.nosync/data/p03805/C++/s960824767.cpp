#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> g[200001];
vector<bool> used(200001);
ll ans = 0, cur = 0;

void dfs(ll u, ll n){
    cur++;
    if(cur == n){
        ans++;
    }
    used[u] = true;
    for(auto x:g[u]){
        if(used[x])continue;
        else dfs(x, n);
    }
    used[u] = false;
    cur--;
}


int main(){
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; ++i){
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, n);
    cout << ans;
    return 0;
}
