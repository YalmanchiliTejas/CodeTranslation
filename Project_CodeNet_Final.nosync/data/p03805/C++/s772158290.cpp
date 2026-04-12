#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    bool graph[n + 1][n + 1];
    for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
        graph[i][j] = false;
    }
    }
    for(int i = 1;i <= m;i++){
        int a,b;
        cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
    }
    int dp[1 << n][n];
    for(int i = 0;i < (1 << n);i++)
        for(int j = 0;j < n;j++)
            dp[i][j] = 0;

    dp[1][0] = 1;
    for(int i = 1;i < (1 << n);i++){
        for(int last = 0;last < n;last++){
            //cout << dp[i][last] << " " << i << " " << last << endl;
            for(int j = 0;j < n;j++){
            if(((1 << j) & i) > 0 || !graph[last][j])continue;
            dp[i | (1 << j)][j] += dp[i][last];
        }
    }
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += dp[(1 << n) - 1][i];
        //cout << ans << " " << dp[1 << n][i] << " " << (1 << n) << " " << i << endl;
    }
        cout << ans;
        return 0;
    }
