#include <vector>
#include <iostream>
#include <limits>
using ll = long long;
constexpr ll INF = 1LL << 60;
using ll = long long;
int main()
{
    int N;
    std::cin >> N;
    std::vector<ll> a(N);
    for (int i = 0; i < N; i++) { std::cin >> a[i]; }
    std::vector<std::vector<ll>> memo(N + 1, std::vector<ll>(N + 1, INF));
    auto dp = [&](auto&& self, const int l, const int r) -> ll {
        if (l > r) { return 0; }
        if (memo[l][r] != INF) { return memo[l][r]; }
        const ll n1 = -self(self, l + 1, r) + a[l];
        const ll n2 = -self(self, l, r - 1) + a[r];
        return memo[l][r] = std::max(n1, n2);
    };
    std::cout << dp(dp, 0, N - 1) << std::endl;
    return 0;
}
