#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 25;

int dp[MAXN][3];
int a[MAXN];

const int INF = 1e18 + 1188;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = -INF;
        dp[i][1] = -INF;
        dp[i][2] = -INF;
    }
    dp[1][0] = a[0];
    dp[2][1] = a[1];
    dp[3][2] = a[2];
    dp[3][0] = a[2] + a[0];
    for (int i = 3; i < n; ++i)
    {
        dp[i + 1][0] = dp[i - 1][0] + a[i];
        dp[i + 1][1] = max(dp[i - 2][0], dp[i - 1][1]) + a[i];
        int c = max(dp[i - 2][1], dp[i - 1][2]);
        c = max(c, dp[i - 3][0]);
        dp[i + 1][2] = c + a[i];
    }
    if (n % 2)
    {
        int mx = dp[n][2];
        mx = max(mx, dp[n - 1][1]);
        mx = max(mx, dp[n - 2][0]);
        cout << mx << endl;
    }
    else
    {
        int mx = dp[n][1];
        mx = max(mx, dp[n - 1][0]);
        cout << mx << endl;
    }
    return 0;
}
