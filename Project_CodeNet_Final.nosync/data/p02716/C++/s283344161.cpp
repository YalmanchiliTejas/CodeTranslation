#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse", "sse2", "avx", "avx2")

#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
const int mod = 1e9 + 7;
const int K = 120;
const int N = 2e5;
int dp[N][4];

signed main() {
    accell();
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = -1e18;
        }
    }
    int cur = 0;
    if (n % 2 == 1)
        cur = 2;
    else
        cur = 1;
    for (int i = 0; i <= cur; ++i) {
        dp[i][i] = max(dp[i][i], a[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int k = 0; k <= cur; ++k) {
            if (dp[i][k] == -1e18)
                continue;
            for (int j = i + 2; j < n; ++j) {
                int del = j - i - 2;
                if (del > cur)
                    break;
                int c = k + del;
                if (c > cur) continue;
                dp[j][c] = max(dp[j][c], dp[i][k] + a[j]);
            }
        }
    }

    int ans = -1e18;
    for (int i = n - 1; i >= n - cur - 1; --i) {
        for (int j = 0; j <= cur - (n - i - 1); ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
