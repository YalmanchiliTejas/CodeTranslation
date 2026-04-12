#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string K;
    cin >> K;

    int D;
    cin >> D;

    const int n = K.size();
    vector<vector<long long>> dp(n, vector<long long>(D, 0));

    for (int i = 0; i < 10; ++i)
        dp[0][i % D] += 1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < D; ++j) {
            for (int k = 0; k < 10; ++k)
                dp[i + 1][j] += dp[i][(((j - k) % D) + D) % D];
            dp[i + 1][j] %= MOD;
        }
    }

    long long cnt = 0, k = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < K[i] - 48; ++j) {
            cnt += dp[n - i - 2][(((-j - k) % D) + D) % D];
        }
        cnt %= MOD;
        k += K[i] - 48;
    }

    for (int j = 0; j < K[n - 1] + 1 - 48; ++j)
        cnt += (j + k) % D == 0;

    cout << (cnt - 1) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << boolalpha;
    cout << fixed << setprecision(16);

    solve();
    return 0;
}
