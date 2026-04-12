#include <cstdio>
#include <vector>
using namespace std;

struct Edge {
    int to;
    int cost;
};

int n;
vector<Edge> es[10000];
vector<int> dp[10000];

int dfs(int i, int j) {
    if (dp[i][j] >= 0) return dp[i][j];
    dp[i][j] = es[i][j].cost;
    int u = es[i][j].to;
    for (int k=0; k<es[u].size(); k++) {
        if (es[u][k].to == i) continue;
        dp[i][j] = max(dp[i][j], dfs(u, k) + es[i][j].cost);
    }
    return dp[i][j];
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        Edge e;
        int a, b;
        scanf("%d%d%d", &a, &b, &e.cost);
        e.to = b;
        es[a].push_back(e);
        dp[a].push_back(-1);
        e.to = a;
        es[b].push_back(e);
        dp[b].push_back(-1);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<es[i].size(); j++) {
            if (dp[i][j] < 0) {
                dp[i][j] = dfs(i, j);
            }
        }
    }

    for (int i=0; i<n; i++) {
        int ans = 0;
        for (int j=0; j<dp[i].size(); j++) {
            ans = max(ans, dp[i][j]);
        }
        printf("%d\n", ans);
    }
}