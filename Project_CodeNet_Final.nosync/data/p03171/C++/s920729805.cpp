#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
#define qmax(a,b) ((a)>(b)?(a):(b))
#define qmin(a,b) ((a)<(b)?(a):(b))

int a[N], n;
long long dp[N][N];
long long sum;

long long dfs(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return 1LL * dp[l][r];
    if (l == r) return 1LL * a[l];
    return dp[l][r] = 1LL * qmax(a[r] + 1LL * qmin(dfs(l, r-2), dfs(l+1, r-1)), a[l] + 1LL * qmin(dfs(l+2, r), dfs(l+1, r-1)));
}

int main() {
    scanf("%d", &n);
    sum = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum = sum + 1LL * a[i];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == j) dp[i][j] = a[i];
            else dp[i][j] = -1;
        }
    }
    dp[1][n] = dfs(1, n);
   // cout << dp[1][n] << " " << sum - dp[1][n] << endl;
    printf("%lld\n", 1LL * 2 * dp[1][n] - 1LL * sum);
    return 0;
}