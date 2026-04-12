#include <bits/stdc++.h>
using namespace std;

#define INF (1LL << 31 - 1)
#define MOD int(1e9+7)
#define repi(i,j,n) for(int i = (j); i < (n); ++i)
#define rep(i,n) repi(i,0,n)
#define fi first
#define se second

inline void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int n, m, a, b;
vector<int> g[8];
bool used[8];

int dfs(int v, int cnt) {
    if (cnt == n) return 1;

    int ret = 0;
    used[v] = true;
    int si = g[v].size();
    for (int i = 0; i < si; ++i) {
        if (!used[g[v][i]]) {
            ret += dfs(g[v][i], cnt + 1);
        }
    }
    used[v] = false;
    return ret;
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b, a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << dfs(0, 1) << endl;

    return 0;
}