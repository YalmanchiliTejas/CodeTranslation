#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector < vector < int > > g(9);

void brute (int u, vector < bool > &used) {
    used[u] = 1;
    for (int v: g[u]) {
        if (!used[v]) {
            brute(v, used);
            used[v] = 0;
        }
    }
    if (count(used.begin(), used.end(), 0) == 1)
        ++ans;
}

signed main () {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector < bool > used(n + 1, 0);
    brute(1, used);
    cout << ans << '\n';
}
