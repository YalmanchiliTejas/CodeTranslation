#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e4 + 10, K = 110, MOD = 1e9 + 7;
int dp[N][K];

int32_t main()
{
    string k; cin >> k;
    int D, n = k.size(); cin >> D;
    for (char c = '0'; c < k[0]; c++) dp[0][(c - '0') % D]++;
    int sum = (k[0] - '0') % D;
    for (int i = 1; i < n; i++) {
        for (char c = '0'; c < k[i]; c++) dp[i][(c - '0' + sum) % D]++, dp[i][(c - '0' + sum) % D]%=MOD;
        for (int j = 0; j < D; j++)
            for (char c = '0'; c <= '9'; c++) dp[i][(c - '0' + j) % D] += dp[i - 1][j], dp[i][(c - '0' + j) % D]%=MOD;
        sum = (k[i] - '0' + sum) % D;
    }
    cout << (dp[n - 1][0] + (sum % D == 0) - 1 + MOD) % MOD << "\n";

    return 0;
}
