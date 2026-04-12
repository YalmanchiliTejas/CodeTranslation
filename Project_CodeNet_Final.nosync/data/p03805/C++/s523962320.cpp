#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)
#define rrep(i, n) for(int i = ((int)n - 1); i >= 0; --i)

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int n;
int res = 0;
vector<vector<int> > g;
vector<bool> visited;

void dfs(int s = 0, int p = -1) {
    bool ok = true;
    rep (i, n) if (!visited[i]) ok = false;
    if (ok) {
        res++;
        return;
    }
    rep (i, g[s].size()) {
        int v = g[s][i];
        if (p == v) continue;
        if (visited[v]) continue;
        visited[v] = true;
        dfs(v, s);
        visited[v] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(0);
    int m;
    cin >> n >> m;
    g.resize(n);
    visited.resize(n);
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visited[0] = true;
    dfs();
    cout << res << endl;
    
    return 0;
}

