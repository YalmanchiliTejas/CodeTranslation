#include <iostream>
#include <algorithm>

using ll = long long int;

int main()
{
    int n;
    std::cin >> n;

    ll a[200010], dp[200010][3] = { 0 };
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    ll ans = -1e15;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            dp[i][j] = -1e15;
        }
        if (i < 3)
            dp[i][i] = a[i];

        if (i-2 >= 0)
        {
            dp[i][0] = std::max(dp[i][0], dp[i-2][0] + a[i]);
            dp[i][1] = std::max(dp[i][1], dp[i-2][1] + a[i]);
            dp[i][2] = std::max(dp[i][2], dp[i-2][2] + a[i]);
        }

        if (i-3 >= 0)
        {
            dp[i][1] = std::max(dp[i][1], dp[i-3][0] + a[i]);
            dp[i][2] = std::max(dp[i][2], dp[i-3][1] + a[i]);
        }

        if (i-4 >= 0)
        {
            dp[i][2] = std::max(dp[i][2], dp[i-4][0] + a[i]);
        }
    }

    if (n & 1)
    {
        ans = std::max(ans, dp[n-1][2]);
        ans = std::max(ans, dp[n-2][1]);
        ans = std::max(ans, dp[n-3][0]);
    }
    else
    {
        ans = std::max(ans, dp[n-1][1]);
        ans = std::max(ans, dp[n-2][0]);
    }

    std::cout << ans;
}
