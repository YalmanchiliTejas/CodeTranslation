#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 3005;

int n;

int a[N], k, dp[N][N], p[N];

int sum (int l, int r) {
    return p[r] - p[l - 1];
}

main () {
    ios_base::sync_with_stdio (0), cin.tie (0), cout.tie (0);
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        dp[i][i] = a[i];
    }
    for (int i = 2;i <= n;i ++) {
        for (int l = 1,r = i;r <= n;l ++,r ++) {
            dp[l][r] = sum (l, r) - min (dp[l + 1][r], dp[l][r - 1]);
        }
    }
    cout << dp[1][n] - sum (1, n) + dp[1][n];
}
