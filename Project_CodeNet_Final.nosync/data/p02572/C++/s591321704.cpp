#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::uint64_t> as(n);
    std::vector<std::uint64_t> asum(n);

    for (std::uint64_t i = 0; i < n; i++)
    {
        std::cin >> as[i];
        if (i == 0)
        {
            asum[i] = as[i];
        }
        else
        {
            asum[i] = asum[i - 1] + as[i];
        }
    }

    constexpr std::uint64_t MOD = 1000000007;

    std::uint64_t ans = 0;
    for (std::uint64_t i = 0; i < as.size() - 1; ++i)
    {
        auto mul = (*asum.rbegin() - asum[i]) % MOD;
        ans += (as[i] * mul) % MOD;
        ans %= MOD;
    }

    std::cout << ans;
    return 0;
}