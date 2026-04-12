#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dp(n);
    function<int(int, int)> Dfs = [&](int x, int p) {
        int v = 0;
        for (int u : g[x]) {
            if (u == p) continue;
            int r = Dfs(u, x);
            dp[x] += dp[u];
            if (r && !v) {
                dp[x]++;
                v = 1;
            }
        }
        return 1 - v;
    };

    Dfs(0, -1);
    if (dp[0] * 2 == n) puts("Second");
    else puts("First");
}
