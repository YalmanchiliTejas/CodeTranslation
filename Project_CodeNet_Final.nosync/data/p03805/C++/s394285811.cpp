#include "bits/stdc++.h"

// Begin {{{
using namespace std;

#ifndef DEBUG
#define dump(...)
#endif

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T>
inline vector<T> make_v(const T &initvalue, size_t sz) {
    return vector<T>(sz, initvalue);
}

template <class T, class... Args>
inline auto make_v(const T &initvalue, size_t sz, Args... args) {
    return vector<decltype(make_v<T>(initvalue, args...))>(sz, make_v<T>(initvalue, args...));
}

constexpr int INF = 0x3f3f3f3f;
constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr size_t    operator""_sz(unsigned long long value) { return value; };
constexpr intmax_t  operator""_im(unsigned long long value) { return value; };
constexpr uintmax_t operator""_um(unsigned long long value) { return value; };
// }}} End

size_t N, M;
vector<size_t> g[10];

auto dp = make_v(-1, 10, (1 << 9));

int64_t dfs(size_t now_node, int bit) {
    if (__builtin_popcount(bit) == N) return 1;
    if (~dp[now_node][bit]) return dp[now_node][bit];

    int ret = 0;
    for (auto &next: g[now_node]) {
        if ((bit >> next) & 1) continue;
        ret += dfs(next, bit | (1 << next));
    }

    return dp[now_node][bit] = ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (size_t i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    cout << dfs(0, 1) << "\n";

    return 0;
}
