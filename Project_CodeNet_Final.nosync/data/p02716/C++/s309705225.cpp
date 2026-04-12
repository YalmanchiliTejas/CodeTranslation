#include <array>
#include <cmath>
#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    constexpr int size        = 200000;
    long long int dp[size][2] = {{0}};

    long long int tmp;
    std::cin >> tmp;
    dp[1][1] = tmp;
    std::cin >> tmp;
    dp[2][0] = std::max(tmp, dp[1][1]);

    if (num >= 3)
    {
        std::cin >> tmp;
        dp[3][0] = std::max(dp[2][0], tmp);
        dp[3][1] = dp[1][1] + tmp;
    }

    for (int i = 4; i <= num; ++i)
    {
        std::cin >> tmp;
        if (i % 2 == 1)
        {
            dp[i][0] = std::max(dp[i - 2][0] + tmp, dp[i - 1][0]);
            dp[i][1] = dp[i - 2][1] + tmp;
        }
        else
        {
            dp[i][0] = std::max(dp[i - 2][0] + tmp, dp[i - 1][1]);
        }
    }

    std::cout << dp[num][0] << std::endl;
}
