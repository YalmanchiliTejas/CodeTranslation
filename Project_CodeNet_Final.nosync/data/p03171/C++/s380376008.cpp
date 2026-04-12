//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const int N = 3010;

int a[N];
ll dp[N][N];

ll solve(int l, int r, int p = 0) {
    if (l == r) {
        return dp[l][r] = a[l] * (p ? -1 : 1);
    }
    if (dp[l][r] < LLONG_MAX) {
        return dp[l][r];
    }
    ll res = 0;
    if (p == 0) {
        res = a[l] + solve(l + 1, r, p ^ 1);
        res = max(res, a[r] + solve(l, r - 1, p ^ 1));
    } else {
        res = -a[l] + solve(l + 1, r, p ^ 1);
        res = min(res, -a[r] + solve(l, r - 1, p ^ 1));
    }
    return dp[l][r] = res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = LLONG_MAX;
        }
    }
    cout << solve(0, n - 1);
    return 0;
}