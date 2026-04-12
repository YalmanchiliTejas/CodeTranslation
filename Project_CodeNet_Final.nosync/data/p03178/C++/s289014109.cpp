#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 87, D = 105, C = 10, MOD = 1e9 + 7;
string s;
int d, dp[N][D][C];
int main()
{
    cin >> s >> d;
    int n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int k = 1; k < C; ++k)
                (dp[i][j][k] += dp[i][j][k - 1]) %= MOD;
            for (int k = 0; k < C; ++k)
                (dp[i + 1][(j + k) % d][k] += dp[i][j][C - 1]) %= MOD;
        }
    }
    reverse(begin(s), end(s));
    int ps = 0, ans = 0;
    for (int i = n; i >= 1; --i) {
        int c = s[i - 1] - '0';
        if (c)
            (ans += dp[i][(d - ps) % d][c - 1]) %= MOD; // x < k
        ps = (ps + c) % d;
    }
    ans += ps == 0; // x == k
    ans += MOD - 1; // x == 0
    cout << ans % MOD << endl;
}
