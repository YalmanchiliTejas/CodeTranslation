#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 3e3 + 5, MOD = 998244353;
int dp[N][N], a[N];

int32_t main()
{
    int n, s, ans = 0; cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][a[i]] = i;
        for (int j = a[i]; j <= s; j++) dp[i][j] += dp[i - 1][j - a[i]], dp[i][j] %= MOD;
        ans += (n - i + 1) * dp[i][s] % MOD, ans %= MOD;
        for (int j = 1; j <= s; j++) dp[i][j] += dp[i - 1][j], dp[i][j] %= MOD;
    }
    cout << ans << "\n";
}
