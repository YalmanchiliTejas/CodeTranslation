#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr ll mod = static_cast<ll>(1e9 + 7);
template<long long Mod = mod>
constexpr long long MOD(long long in) {
    return in % Mod;
}

int n;
ll a[100005];
ll dp[100005];
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::fill(dp, dp + n + 1, inf);
    std::reverse(a, a + n);
    for (int i = 0; i < n; ++i) {
        *std::upper_bound(dp, dp + n, a[i]) = a[i];
    }

    std::cout << std::lower_bound(dp, dp + n, inf) - dp << std::endl;
    return 0;
}
