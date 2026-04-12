#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<vector<int>> g;

bool dfs(int v, int p, int &c) {
    int cnt = 0;
    for (int u : g[v]) {
        if (u == p) continue;
        int c;
        if (dfs(u, v, c)) return true;
        if (c == 0) cnt++;
    }
    if (cnt >= 2) return true;
    else c = cnt;
    return false;
}

int main() {
    int n; cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int c;
    if (dfs(0, -1, c) || c == 0) puts("First");
    else puts("Second");
    return 0;
}