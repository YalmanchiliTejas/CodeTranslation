#include <bits/stdc++.h>

using namespace std;

int n;
int v[3010];
long long dp[3010][3010][2];

long long f(int i, int j, int flag) {
    if(i > j) return 0;
    
    long long &ans = dp[i][j][flag];
    if(ans != -1) return ans;
    ans = flag ? -1e18 : 1e18;

    if(flag) {
        ans = max(ans, f(i + 1, j, !flag) + v[i]);
        ans = max(ans, f(i, j - 1, !flag) + v[j]);
    } else {
        ans = min(ans, f(i + 1, j, !flag) - v[i]);
        ans = min(ans, f(i, j - 1, !flag) - v[j]);
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    cout << f(0, n - 1, 1) << "\n";
    
    return 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; j--) {
            if(j <= i) continue;
            dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] + v[j]);
            dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j][0] + v[i]);
            dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] - v[i]);
            dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][1] - v[j]);
        }
    }
    
    cout << dp[0][n - 1][1] << "\n";
    return 0;
}
