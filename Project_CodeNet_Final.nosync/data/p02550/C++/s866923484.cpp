#include <bits/stdc++.h>
using Int = long long;  // clang-format off
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sat Sep 19 21:06:18 JST 2020
 **/

signed main() {
    Int n, x, m;
    std::cin >> n >> x >> m;
    std::vector<Int> memo(m + 2, x);
    std::vector<Int> cnt(m, -1);
    REP(i, m + 1) {
        if (cnt[memo[i]] != -1) {
            Int ans = 0, tmp = 0;
            REP(j, std::min(n, cnt[memo[i]])) ans += memo[j];
            REP(j, cnt[memo[i]], i) tmp += memo[j];
            Int rem = n - cnt[memo[i]];
            if (rem > 0) {
                Int cycle = i - cnt[memo[i]];
                ans += tmp * (rem / cycle);
                REP(j, cnt[memo[i]], cnt[memo[i]] + rem % cycle) ans += memo[j];
            }
            std::cout << ans << std::endl;
            return 0;
        }
        cnt[memo[i]] = i;
        memo[i + 1] = memo[i] * memo[i] % m;
    }
}
