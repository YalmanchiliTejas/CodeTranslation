#include <bits/stdc++.h>

typedef long long ll;
const ll MOD = 1000000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int d;
    cin >> s >> d;
    int n = s.length();
    vector<vector<vector<ll> > > dp(n + 1, vector<vector<ll> >(d, vector<ll>(2, 0)));
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            // r == 1
            int digit = s[i] - '0';
            for (int k = 0; k < digit; k++) {
                dp[i + 1][(j + k) % d][0] += dp[i][j][1];
                dp[i + 1][(j + k) % d][0] %= MOD;
            }
            dp[i + 1][(j + digit) % d][1] += dp[i][j][1];
            dp[i + 1][(j + digit) % d][1] %= MOD;
            // r == 0
            for (int k = 0; k < 10; k++) {
                dp[i + 1][(j + k) % d][0] += dp[i][j][0];
                dp[i + 1][(j + k) % d][0] %= MOD;
            }
        }
    }

    cout << (dp[n][0][0] + dp[n][0][1] + MOD - 1) % MOD;
    return 0;
}