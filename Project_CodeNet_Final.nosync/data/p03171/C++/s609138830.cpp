#include <bits/stdc++.h>
using namespace std;
long long n, arr[3010], dp[3010][3010];
long long fun(long long x, long long y)
{
    if (x > y)
        return 0;
    if (x > n - 1 || y < 0)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    if ((n - 1 - (y - x)) % 2 == 0)
        return dp[x][y] = max(arr[x] + fun(x + 1, y), arr[y] + fun(x, y - 1));
    return dp[x][y] = min(fun(x + 1, y) - arr[x], fun(x, y - 1) - arr[y]);
}
int main()
{
    cin >> n;
    for (long long x = 0; x < n; x++)
        cin >> arr[x];
    memset(dp, -1, sizeof(dp));
    long long ans = fun(0, n - 1);
    cout << ans << endl;
}