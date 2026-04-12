#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define rep(i, a, b) for(int i = a; i < b; ++i)

int debug = 0;

const int N = 3e5;
int n, INF = 1e15;
int a[N], dp[N][2];

int get_dp(int n, int k) {
    if (n < 0) {
        return 0;
    }
    if (k == n / 2) {
        return dp[n][0];
    } else if (k == n / 2 + 1) {
        return dp[n][1];
    } else if (k > n / 2 + 1) {
        return -INF;
    }
}

main() {
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    dp[0][0] = 0;
    dp[0][1] = -INF;
    int OddFlag = n % 2;
    rep(i, 1, n + 1) rep(k, i/2, i/2 + 2) {
        dp[i][k - i/2] = max(get_dp(i - 2, k - 1) + a[i], get_dp(i - 1, k));
        if (debug) {
            printf("i: %d   K: %d dp: %d\n", i, k, dp[i][k]);
        }
    }
    cout << dp[n][0] << endl;
}