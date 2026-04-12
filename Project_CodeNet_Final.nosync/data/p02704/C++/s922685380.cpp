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
 *    created: Sun May  3 13:27:58 JST 2020
 **/

template <class T, class S> T make_vec(S x) { return x; }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return std::vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}

void no() {
    std::cout << -1 << std::endl;
    exit(0);
}

using ull = unsigned long long;
const Int K = 64;
signed main() {
    Int n;
    std::cin >> n;
    std::vector<Int> S(n), T(n);
    std::vector<ull> U(n), V(n);
    REP(i, n) std::cin >> S[i];
    REP(i, n) std::cin >> T[i];
    REP(i, n) std::cin >> U[i];
    REP(i, n) std::cin >> V[i];
    auto solve_1bit = [&n](const std::vector<Int>& x, const std::vector<Int>& y) {
        auto ret = make_vec<Int>(n, n, -1);
        auto row = make_vec<Int>(n, 2, true);
        auto col = make_vec<Int>(n, 2, true);
        REP(i, n) {
            if (x[i] < 2) row[i][x[i]] = false;
        }
        REP(j, n) {
            if (y[j] < 2) col[j][y[j]] = false;
        }
        REP(i, n) {
            REP(j, n) {
                if (x[i] >= 2) ret[i][j] = x[i] - 2;
                if (y[j] >= 2) ret[i][j] = y[j] - 2;
                if (x[i] == y[j] && x[i] < 2) ret[i][j] = x[i];

                if (ret[i][j] != -1) row[i][ret[i][j]] = col[j][ret[i][j]] = true;
            }
        }
        Int cnti = std::count_if(x.begin(), x.end(), [](Int a) { return a < 2; });
        Int cntj = std::count_if(y.begin(), y.end(), [](Int a) { return a < 2; });
        if (cnti <= 1 || cntj <= 1) {
            // 貪欲
            REP(i, n) {
                REP(j, n) {
                    if (ret[i][j] != -1) continue;
                    if (row[i][0] && col[j][0]) {
                        ret[i][j] = 1;
                    } else {
                        ret[i][j] = 0;
                    }
                    row[i][ret[i][j]] = col[j][ret[i][j]] = true;
                }
            }
        } else {
            // 2*2以上なら市松でOK
            Int ci = 0;
            REP(i, n) {
                if (x[i] >= 2) continue;
                Int cj = 0;
                REP(j, n) {
                    if (y[j] >= 2) continue;
                    ret[i][j] = (ci + cj) % 2;
                    cj++;
                }
                ci++;
            }
        }
        return ret;
    };
    auto ans = make_vec<ull>(n, n, 0);
    REP(k, K) {
        std::vector<Int> x(n), y(n);
        auto trans = [](Int p, Int q) {
            if (p == 0 && q == 0) return 0;
            if (p == 1 && q == 1) return 1;
            if (p == 1 && q == 0) return 2;
            if (p == 0 && q == 1) return 3;
            assert(0);
        };
        REP(i, n) x[i] = trans(S[i], U[i] >> k & 1);
        REP(j, n) y[j] = trans(T[j], V[j] >> k & 1);
        auto tmp = solve_1bit(x, y);
        REP(i, n) {
            REP(j, n) { ans[i][j] |= ull(tmp[i][j]) << k; }
        }
    }

    // verify
    ull all = 0;
    REP(i, K) all |= 1ull << i;
    REP(i, n) {
        ull acc = S[i] ? 0 : all;
        REP(j, n) {
            if (S[i]) {
                acc |= ans[i][j];
            } else {
                acc &= ans[i][j];
            }
        }
        if (acc != U[i]) no();
    }
    REP(j, n) {
        ull acc = T[j] ? 0 : all;
        REP(i, n) {
            if (T[j]) {
                acc |= ans[i][j];
            } else {
                acc &= ans[i][j];
            }
        }
        if (acc != V[j]) no();
    }
    REP(i, n) {
        REP(j, n) std::cout << ans[i][j] << " ";
        std::cout << "\n";
    }
}
