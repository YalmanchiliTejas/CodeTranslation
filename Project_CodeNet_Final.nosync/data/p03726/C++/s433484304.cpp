#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    vector< vector<int> > G(N);
    for(int i=0; i+1<N; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector< vector<int> > dp(N, vector<int>(2));
    auto dfs = [&](auto &&self, int cur, int par) -> void {
        int cnt[2] = {}, deg = 0;
        for(auto to : G[cur]) {
            if(to == par) continue;
            self(self, to, cur);
            deg++;
            for(int k=0; k<2; k++) cnt[k] += dp[to][k];
        }

        dp[cur][0] = 1;
        for(auto to : G[cur]) {
            if(to == par) continue;
            dp[cur][0] &= dp[to][1];
            dp[cur][1] |= (dp[to][0] and deg - 1 == cnt[1] - dp[to][1]);
        }
        // fprintf(stderr, "cur = %d, dp = (%d, %d)\n", cur, dp[cur][0], dp[cur][1]);
    };

    dfs(dfs, 0, -1);
    printf("%s\n", (dp[0][1] ? "Second" : "First"));
    return 0;
}
