#include <iostream>

using ll = long long int;

constexpr int MAX = 3010;
constexpr ll mod = 998244353;

ll dp[MAX][MAX];
int a[MAX];

int main()
{
    int n, s;
    std::cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    ll ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        dp[i][a[i]] = i;
        if (a[i] == s)
            ans = (ans + i * (n - i + 1)) % mod;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int sum = 1; sum < s; ++sum)
        {
            dp[i][sum] = (dp[i][sum] + dp[i - 1][sum]) % mod;
            if (sum > a[i])
                dp[i][sum] = (dp[i][sum] + dp[i - 1][sum - a[i]]) % mod;
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        if (s > a[i])
            ans = (ans + dp[i - 1][s - a[i]] * (n - i + 1)) % mod;
    }
    std::cout << ans << std::endl;
}