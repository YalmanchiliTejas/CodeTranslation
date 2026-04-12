#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 3011, mod = 998244353;
int dp[maxn][maxn];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> mas(n, 0);
    for (int d = 0; d < n; d++) {
        cin >> mas[d];
    }
    dp[0][0] = 1;
    for (int d = 1; d <= n; d++) {
        dp[d][0] = d + 1;
        dp[d][mas[d - 1]] = dp[d - 1][mas[d - 1]] + d;
        //cout << dp[d][0] << " ";
        for (int s1 = 1; s1 <= s; s1++) {
            if (s1 != mas[d - 1]) {
                dp[d][s1] = dp[d - 1][s1];
                if (s1 >= mas[d - 1]) {
                    dp[d][s1] += dp[d - 1][s1 - mas[d - 1]];
                }
             }
             dp[d][s1] %= mod;
             //cout << dp[d][s1] << " ";
        }
        //cout << "\n";
    }
    int ans = 0;
    int tk = 1;
    for (int d = n - 1; d >= 0; d--) {
        if (s >= mas[d]) {
            ans += tk * dp[d][s - mas[d]];
            ans %= mod;
        }
        tk++;
    }
    cout << ans;
}
