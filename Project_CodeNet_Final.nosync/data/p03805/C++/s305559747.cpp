// Author: Vamsi Krishna Reddy Satti
// With love for Competitive Programming!
 
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
 
using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;
using ld = long double;
 
// ------------------------------------------------------------------------------------------------

ll n, m, ans;
vll visited;
vvll g;

void dfs(ll u, ll depth = 1) {
    visited[u] = 1;
    if (depth == n) {
        ans++;
    }
    for (ll &v : g[u]) {
        if (visited[v]) {
            continue;
        }
        dfs(v, depth + 1);
    }
    visited[u] = 0;
}

int main() {
    fast_io; cout_precision;
    cin >> n >> m;
    g.resize(n + 1);
    for (ll i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = 0;
    visited.resize(n + 1);
    dfs(1);
    cout << ans << endl;
}