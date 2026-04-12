#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.length();
    
    long long dp[n+10][2][5] = {0};
    for (int i = 0; i < n+10; i++) {
        for (int j = 0; j < 2; j++) {
            for (int l = 0; l < 5; l++) {
                dp[i][j][l] = 0;
            }
        }
    }
    
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        const int d = s[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int l = 0; l <= k; l++) {
                for (int m = 0; m <= (j ? 9 : d); m++) {
                    if (m == 0) dp[i+1][j || (m < d)][l] += dp[i][j][l];
                    else dp[i+1][j || (m < d)][l+1] += dp[i][j][l];
                }
            }
        }
    }
    
    long long ans = dp[n][0][k] + dp[n][1][k];
    cout << ans << endl;
    return 0;
}