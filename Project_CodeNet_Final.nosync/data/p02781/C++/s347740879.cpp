#include <bits/stdc++.h>  // clang-format off
using namespace std;
using Int = long long;
#define REP2(i, n) for (Int i = 0, max_i = (n); i < max_i; i++)
#define REP3(i, a, b) for (Int i = (a), max_i = (b); i < max_i; i++)
#define OVERLOAD2(_1, _2, _3, name, ...) name
#define REP(...) OVERLOAD2(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
struct SetupIO { SetupIO() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); } } setup_io;
#ifndef _MY_DEBUG
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Feb  9 21:00:01 JST 2020
 **/

template <class T, class S> vector<T> make_vec(size_t n, S x) { return vector<T>(n, x); }
template <class T, class... Ts> auto make_vec(size_t n, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(n, make_vec<T>(ts...));
}

signed main() {
    string s;
    cin >> s;
    Int n = s.size();
    Int K;
    cin >> K;
    auto dp = make_vec<Int>(n + 1, 2, K + 2, 0);
    dp[0][0][0] = 1;
    REP(i, n) {
        REP(j, 2) {
            REP(k, K + 1) {
                REP(d, j ? 10 : s[i] - '0' + 1) { dp[i + 1][j | (d < s[i] - '0')][k + bool(d)] += dp[i][j][k]; }
            }
        }
    }
    cout << dp[n][0][K] + dp[n][1][K] << endl;
}
