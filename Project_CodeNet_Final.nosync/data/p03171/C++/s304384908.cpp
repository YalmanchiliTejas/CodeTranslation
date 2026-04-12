#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll dp[3010][3010];
int a[3010];
ll f(int l, int r)
{
    if (l == r) return a[l];
    ll &ret = dp[l][r];
    if (~ret) return ret;
    return ret = max(a[l] - f(l+1, r), a[r] - f(l, r-1));
}
int main()
{
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%lld\n", f(0, n-1));

    return 0;
}
