#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

ll n, m;
vvl G;
vl visited;
ll ans = 0;

void dfs(ll v) {
    ll ok = 1;
    rep(i, n) {
        if(visited[i] == 0) {
            ok = 0;
        }
    }
    if(ok) {
        ans++;
    }
    for(auto u : G[v]) { 
        if(visited[u]) {
            continue;
        }
        visited[u] = 1;
        dfs(u);
        visited[u] = 0;
    }
}

int main() {
    
    cin >> n >> m;    

    G.resize(n);
    visited.resize(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    visited[0] = 1;
    dfs(0);

    out(ans);
    re0;
}