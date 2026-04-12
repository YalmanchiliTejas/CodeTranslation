#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using p  = pair<ll, ll>;

ll dfs(ll node, vector<vector<ll> >& G, vector<bool> used) {
    used[node] = true;
    
    bool end = true;
    for (auto b : used) {
        end &= b;
    }
    if (end) {
        return 1;
    }
    
    ll ans = 0;
    for (auto n : G[node]) {
        if (!used[n]) {
            ans += dfs(n, G, used);
        }
    }
    
    return ans;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N, M;
    cin >> N >> M;
    vector<bool> used(N, false);
    vector<vector<ll> > G(N, vector<ll>());
    
    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    cout << dfs(0, G, used) << endl;

    return 0;
}

