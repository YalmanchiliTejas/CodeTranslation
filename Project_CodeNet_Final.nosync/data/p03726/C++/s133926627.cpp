#define ENABLE_DEBUG 1
// Kana's kitchen {{{
#include<bits/stdc++.h>
#define ALL(v) std::begin(v), std::end(v)
#define REP(i, k) for (decltype(k) i = 0; i < k; i++)
#define LOOP(k) REP (ngtkana_is_a_genius, k)

using i32 = std::int_least32_t;
using i64 = std::int_least64_t;
using u32 = std::uint_least32_t;
using u64 = std::uint_least64_t;
using usize = std::size_t;

template <class T, class U> using pair = std::pair<U, T>;
template <class T> using diag_pair = std::pair<T, T>;
template <class... Args> using tuple = std::tuple<Args...>;
template <class T> using vec = std::vector<T>;
template <class T> using numr = std::numeric_limits<T>;

#ifdef NGTKANA
#include<debug.hpp>
#else
#define DEBUG(...)(void)0
#endif
/*}}}*/
template <class F>
class fixed_point {
    F f;
public:
    fixed_point(F&& f_) : f(f_) {}
    template <class... Args> auto operator()(Args... args) { return f(f, args...); }
};
template <class F> auto make_fixed_point(F&& f) { return fixed_point<F>(std::forward<F&&>(f)); }

void err() {
    std::cout << "First" << '\n';
    exit(0);
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::setprecision(15) << std::fixed;

    u32 n; std::cin >> n;
    if (n%2) err();
    vec<vec<u32>> g(n);
    LOOP (n-1) {
        u32 u, v; std::cin >> u >> v; u--, v--;
        g.at(u).push_back(v);
        g.at(v).push_back(u);
    }

    vec<u32> a(n);
    make_fixed_point(
        [&](auto&& dfs, u32 x, u32 p) -> bool {
            bool found = false;
            for (u32 y: g.at(x)) if (y!=p) {
                if (dfs(dfs, y, x) && std::exchange(found, true)) err();
            }
            return !found;
        }
    )(0, 0);

    std::cout << "Second" << '\n';
}
