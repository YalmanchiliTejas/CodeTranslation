#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long dp[10010][110][11];
int main() {
    string s; cin >> s;
    int d; cin >> d;
    dp[0][0][10] = 1; dp[0][0][0] = 1;
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i+1][(j+k)%d][k] += dp[i][j][10];
                dp[i+1][(j+k)%d][10] += dp[i][j][10];
                dp[i+1][(j+k)%d][k] %= mod;
                dp[i+1][(j+k)%d][10] %= mod;
            }
        }
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                if (dp[i+1][j][k] == 0) continue;
            }
        }
    }
    long long ans = -1; int k = 0;
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] - '0';
        for (int u = 0; u < t; u++) {
            ans += dp[s.size()-i][(d-k)%d][u];
            ans %= mod;
        }
        k = (k+t) % d;
    }
    ans = (ans+dp[0][(d-k)%d][0]) % mod;
    cout << ans << endl;
    return 0;
}