#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 200'010;
ll a[N], dp[3][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    dp[0][1] = a[1];
    dp[1][2] = a[2];
    if (n >= 3) {
        dp[0][3] = a[1] + a[3];
        dp[2][3] = a[3];
    }
    for (int i = 4; i <= n; i++) {
        if (i % 2 == 1) {
            dp[0][i] = dp[0][i - 2] + a[i];
            dp[2][i] = dp[2][i - 2] + a[i];
            dp[2][i] = max(dp[2][i], dp[1][i - 3] + a[i]);
            dp[2][i] = max(dp[2][i], dp[0][i - 4] + a[i]);
        } else {
            dp[1][i] = dp[1][i - 2] + a[i];
            dp[1][i] = max(dp[1][i], dp[0][i - 3] + a[i]);
        }
    }
    ll ans;
    if (n % 2 == 0) {
        ans = max(dp[0][n - 1], dp[1][n]);
    } else {
        ans = max(dp[0][n - 2], dp[1][n - 1]);
        ans = max(ans, dp[2][n]);
    }
    printf("%lld\n", ans);
}
