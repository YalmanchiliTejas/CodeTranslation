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
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
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

vvl G;
vl visited;
ll n, m;
ll ans = 0;

void dfs(ll v) {
    // 行きの処理はこのへんに書く
    visited[v] = 1;
    for(auto u : G[v]) { 
        if(visited[u]) {
            continue;
        }
        dfs(u);
        // 帰りの処理はこのへんに書く
    }
    bool ok = true;  // すべての頂点を訪れていたらtrue
    rep(v, n) {
        if(visited[v] == 0) {
            ok = false;
        }
    }
    if(ok) {
        ans++;
    }
    visited[v] = 0;
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
    
    dfs(0);

    out(ans);
    re0;
}