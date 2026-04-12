#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 3010;
int a[maxn], dp[maxn][maxn][2], n;

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        dp[i][i][0] = a[i], dp[i][i][1] = -a[i];
    for (int l = 2; l <= n; l++)
        for (int i = 0; i + l - 1 < n; i++)
        {
            int j = i + l - 1;
            dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);
            dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]);
        }

    cout << dp[0][n - 1][0];

    return 0;
}
