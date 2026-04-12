#include <iostream>
#include <algorithm>

using ll = long long int;

constexpr int MAX_N = 2 * 1e5 + 10;

int n;
ll a[MAX_N];
ll dp[MAX_N][2];

int main()
{
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {

        std::cin >> a[i];
    }

    dp[1][0] = 0;
    dp[1][1] = a[1];

    if (n % 2)
    {
        for (int i = 2; i <= n; ++i)
        {
            if (i % 2)
            {
                dp[i][0] = std::max(dp[i - 1][1], dp[i - 2][0] + a[i]);
                dp[i][1] = dp[i - 2][1] + a[i];
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = std::max(dp[i - 1][1], dp[i - 2][1] + a[i]);
            }
        }
    }

    else
    {
        for (int i = 2; i <= n; ++i)
        {
            if (i % 2)
            {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 2][1] + a[i];
            }
            else
            {
                dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][0] + a[i]);
            }
        }
    }

    std::cout << dp[n][0] << std::endl;

    return 0;
}