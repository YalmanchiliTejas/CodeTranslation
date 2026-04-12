#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int dp[N][2];
vector <int> g[N];

void dfs(int v, int p = 0) {
    for (int u : g[v]) if (u != p) dfs(u, v), dp[v][0] += dp[u][1];
    for (int u : g[v]) if (u != p) dp[v][1] = max(dp[v][1], dp[v][0] - dp[u][1] + dp[u][0] + 1);
}
int main() {
    int n; cin >> n;
    if (n % 2 == 1) return cout << "First\n", 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1);
    if (dp[1][1] == n/2) cout << "Second\n";
    else cout << "First\n";

    return 0;
}
