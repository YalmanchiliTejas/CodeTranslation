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
 *    created: Sun Aug  2 21:13:28 JST 2020
 **/

signed main() {
    Int x;
    std::cin >> x;
    std::cout << (x >= 30 ? "Yes" : "No") << std::endl;
}
