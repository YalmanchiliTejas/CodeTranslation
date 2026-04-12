#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Apr 12 21:00:01 JST 2020
 **/

template <class T, class S> T make_vec(S x) { return x; }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return std::vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}

signed main() {
    Int n;
    std::cin >> n;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    if (n % 2 == 0) {
        auto dp = make_vec<Int>(n + 1, 2, 0);
        REP(i, n) {
            dp[i + 1][0] = dp[i][0] + (i % 2 ? 0 : a[i]);
            dp[i + 1][1] = std::max(dp[i][0], dp[i][1] + (i % 2 ? a[i] : 0));
        }
        std::cout << std::max(dp[n][0], dp[n][1]) << std::endl;
        return 0;
    }
    auto dp = make_vec<Int>(n + 1, 3, 0);
    REP(i, n) {
        dp[i + 1][0] = dp[i][0] + (i % 2 ? 0 : a[i]);
        dp[i + 1][1] = std::max(dp[i][0], dp[i][1] + (i % 2 ? a[i] : 0));
        dp[i + 1][2] = std::max({dp[i][1], dp[i][2] + (i % 2 || i == 0 ? 0 : a[i])});
    }
    std::cout << std::max({dp[n - 2][0], dp[n][1], dp[n][2]}) << std::endl;
}
