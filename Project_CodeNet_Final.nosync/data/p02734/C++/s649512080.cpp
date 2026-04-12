//
// Created by munaiyi on 2020/3/26.
//
#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int maxn = 3e3 + 5;

int dp[maxn][maxn];
int a[maxn];

int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[1][a[1]] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) {
                dp[i][j] = dp[i][j] + dp[i - 1][j - a[i]];
                if (dp[i][j] >= mod) dp[i][j] -= mod;
            }
        }
        dp[i][0]++;
        dp[i][a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i][s];
        if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
    return 0;
}
