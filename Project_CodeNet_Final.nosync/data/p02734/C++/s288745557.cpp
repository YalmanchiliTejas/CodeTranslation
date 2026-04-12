#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define rep(i, a, b) for(int i = a; i < b; ++i)

int debug = 0;

const int N = 3010;
int mod = 998244353;
int n, s, ans, all, a[N], dp[N][N];

main() {
    cin >> n >> s;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    ans = 0;
    rep(i, 1, n + 1) {
        rep(w, 0, s + 1) {
            dp[i][w] = dp[i - 1][w];
            if (w > a[i]) {
                (dp[i][w] += dp[i - 1][w - a[i]]) %= mod;
            } else if (a[i] == w) {
                (dp[i][w] += i) %= mod;
            }
            if (debug) {
                cerr << dp[i][w] - dp[i - 1][w] << ' ';
            }
        }
        if (debug) {
            cerr  << '\n';
        }
        (ans += (dp[i][s] - dp[i - 1][s] + mod + mod) * (n + 1 - i)) %= mod;
    }
    cout << ans << '\n';
}