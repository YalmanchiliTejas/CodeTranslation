#include <bits/stdc++.h>
using namespace std;

long long dp[200100][10];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = -1e18;
        }
    }
    int offset = 4;
    dp[0][0+offset] = 0;
    dp[1][1+offset] = a[0];
    dp[1][0+offset] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= min(i, 4); j++) {
            for (int k = -4; k < 5; k++) {
                // dp[i-j][k+offset]
                // (i-j)/2 + k + 1 = x + i/2;
                int x = (i-j)/2 + k + 1 - i/2;
                if (x > 4 || x < -4) continue;
                dp[i][x+offset] = max(dp[i][x+offset], dp[i-j][k+offset] + a[i-1]);
            }
        }
        for (int k = -4; k < 5; k++) {
            int x = (i-1)/2 + k - i/2;
            if (x > 4 || x < -4) continue;
            dp[i][x+offset] = max(dp[i][x+offset], dp[i-1][k+offset]);
        }
    }
    cout << dp[n][0+offset] << "\n";
    return 0;
}