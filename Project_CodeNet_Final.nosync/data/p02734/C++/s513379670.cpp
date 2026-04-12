#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
int p = 998244353, dp[3010], n, s, ans, x[3010];
int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x[i]);
        dp[0] = i;
        for (int j = s; j >= x[i]; --j)
            dp[j] = (dp[j] + dp[j - x[i]]) % p;
        ans = (ans + dp[s]) % p;
    }
    cout << ans << endl;
    return 0;
}
// #include <cstdio>
// int p = 998244353, dp[3010], n, s, ans, x[3010];
// int main()
// {
//     scanf("%d%d", &n, &s);
//     for (int i = 1; i <= n; ++i)
//     {
//         scanf("%d", &x[i]);
//         dp[0] = i;
//         for (int j = s; j >= x[i]; --j)
//             dp[j] += dp[j - x[i]];
//         ans = (ans + dp[s]);
//     }
//     printf("%d", ans);
//     return 0;
// }