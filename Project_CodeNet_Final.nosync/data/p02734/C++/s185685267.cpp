#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)3e3;
const ll mod = (ll)998244353;

int a[M + 5];
int dp[M + 5][M + 5];
int sum[M + 5];

int main()
{
    int n, s; scanf("%d %d", &n, &s);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        dp[i][a[i]] = i;
        for(int j = s; j >= a[i]; --j) dp[i][j] = (dp[i][j] + sum[j - a[i]]) % mod, sum[j] = (sum[j] + dp[i][j]) % mod;
        ans = (ans + 1ll * dp[i][s] * (n - i + 1)) % mod;
    }
    printf("%d\n", ans);
    return 0;
}
