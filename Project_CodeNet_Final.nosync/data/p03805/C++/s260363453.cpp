#include <bits/stdc++.h>

using namespace std;

vector<int> edge[10];
int dp[1024][10];

int main()
{
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dp[1][0] = 1;
    for (int mask = 2; mask < (1 << n); mask++){
        for (int u = 0; u < n; u++){
            if (mask & (1 << u)){
                for (auto v: edge[u]){
                    if (mask & (1 << v)){
                        dp[mask][u] += dp[mask ^ (1 << u)][v];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += dp[(1 << n) - 1][i];
    }
    cout << ans;
    return 0;
}

