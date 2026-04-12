#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Jun 14 16:33:01 JST 2020
 **/

signed main() {
    Int n;
    std::cin >> n;
    std::vector<Int> a(n);
    REP(i, n) std::cin >> a[i];
    Int Q;
    std::cin >> Q;
    REP(q, Q) {
        Int k;
        std::cin >> k;
        std::cout << std::lower_bound(a.begin(), a.end(), k) - a.begin() << "\n";
    }
}

