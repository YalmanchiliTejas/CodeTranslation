#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main() {
    string K;
    int D;
    cin >> K >> D;

    int N = K.length();
    
    int dp[N+1][D][2];
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < D; j++) {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    dp[0][0][0] = 1;

    for (int i = 1; i < N+1; i++) {
        for (int j = 0; j < D; j++) {
            dp[i][(j+(K[i-1] - '0')) % D][0] += dp[i-1][j][0];
            for (int k = 0; k < K[i-1] - '0'; k++) {
                dp[i][(j+k) % D][1] += dp[i-1][j][0];
            }
            for (int k = 0; k < 10; k++) {
                dp[i][(j+k) % D][1] += dp[i-1][j][1];
            }
            
            dp[i][j][0] %= mod;
            dp[i][j][1] %= mod;
        }
    }

    int ans = (dp[N][0][0] + dp[N][0][1] - 1) % mod;
    cout << ans << endl;
}