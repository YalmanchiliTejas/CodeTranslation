#include <bits/stdc++.h>

typedef long long ll;
const ll mo = 998244353;
const int maxn = 4096;

int n, s, a[maxn];
ll ans, dp[maxn];

int main() {
    scanf("%d%d", &n, &s);
    for(int i = 0; i < n; ++i)
        scanf("%d", a + i);
    dp[0] = 1;
    dp[a[0]] = 1;
    ans = dp[s];
    for(int i = 1; i < n; ++i) {
        for(int j = s; j >= a[i]; --j)
            dp[j] = (dp[j] + dp[j - a[i]]) % mo;
        dp[0] = (dp[0] + 1) % mo;
        dp[a[i]] = (dp[a[i]] + 1) % mo;
        ans = (ans + dp[s]) % mo;
    }
    printf("%lld\n", ans);
    return 0;
}