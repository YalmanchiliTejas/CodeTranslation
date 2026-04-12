#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll c = 0;
vector<vector<ll>> v;

void dfs(ll node, vector<bool> visited) {
    visited[node] = true;
    bool isok = true;
    rep(i, visited.size()) {
        isok = isok && visited[i];
    }
    if (isok) {
        c++;
        return;
    }
    rep(i, v[node].size()) {
        if (!visited[v[node][i]]) dfs(v[node][i], visited);
    }
}

int main()
{
    ll n, m; cin >> n >> m;
    v.resize(n);
    
    rep(i, m) {
        ll a, b; cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    dfs(0, vector<bool>(n, false));

    cout << c << endl;
    return 0;
}