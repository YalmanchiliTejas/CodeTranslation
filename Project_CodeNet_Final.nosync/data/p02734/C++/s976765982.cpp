#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll MOD = 998244353;

ll dp[3005][3005];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j >= a[i]) {
                ll hoge = dp[i][j - a[i]] * (j == a[i] ? i + 1 : 1) % MOD;
                (dp[i + 1][j] += hoge) %= MOD;
                if (j == s) (ans += hoge * (n - i) % MOD) %= MOD;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}