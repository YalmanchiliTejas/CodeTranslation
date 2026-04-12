#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 3010, mod = 998244353;
int dp[maxn][maxn], a[maxn], n, s;

signed main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n >> s;
        for (int i = 0; i < n; i++) {
                cin >> a[i];
                dp[i][0] = dp[i][a[i]] = i + 1;
        }
        for (int i = 1; i < n; i++) {
                for (int k = 1; k <= s; k++) {
                        (dp[i][k] = dp[i - 1][k] + (k > a[i] ? dp[i - 1][k - a[i]] : 0) + (k == a[i] ? i + 1 : 0)) %= mod;
                }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
                (ans += dp[i][s]) %= mod;
        }
        cout << ans;

        return 0;
}