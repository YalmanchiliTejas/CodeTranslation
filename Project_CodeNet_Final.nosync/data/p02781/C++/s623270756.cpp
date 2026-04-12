#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string n;
    int k;
    cin >> n >> k;
    int len = n.length();
    ll dp[n.length() + 1][k + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= len; i++) {
        dp[i][0][0] = 1;
    }
    dp[1][1][0] = n[0] - '1';
    dp[1][1][1] = 1;
    for (int i = 2; i <= len; i++) {
        for (int l = 1; l <= k; l++) {
            ll val0 = dp[i - 1][l][0] + dp[i - 1][l - 1][0] * 9;
            ll val1;
            if (n[i - 1] != '0') {
                val0 += dp[i - 1][l][1] + dp[i - 1][l - 1][1] * (n[i - 1] - '0' - 1);
                val1 = dp[i - 1][l - 1][1];
            } else {
                val1 = dp[i - 1][l][1];
            }
            dp[i][l][0] = val0;
            dp[i][l][1] = val1;
        }
    }
    cout << dp[len][k][0] + dp[len][k][1] << endl;
    return 0;
}
