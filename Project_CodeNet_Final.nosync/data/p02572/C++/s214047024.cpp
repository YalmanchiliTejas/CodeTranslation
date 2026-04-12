#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>

namespace adaptor = boost::adaptors;

const int64_t MOD = 1000000007;

void solve()
{
    int64_t N;
    std::cin >> N;
    std::vector<int64_t> A(N);
    for (auto& v : A) std::cin >> v;

    std::vector<int64_t> cum(N + 1);
    cum[0] = 0;
    for (int64_t i = 1; i < N + 1; i++)
    {
        cum[i] = cum[i - 1] + A[i - 1];
    }

    int64_t ans = 0;
    for (int64_t i = 0; i < N; i++)
    {
        int64_t sum = (cum[N] - cum[i + 1]) % MOD;
        ans += sum * A[i];
        ans %= MOD;
    }

    std::cout << ans << std::endl;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
