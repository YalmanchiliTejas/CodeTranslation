#define ENABLE_DEBUG 1
// Kana's kitchen {{{
#include<bits/stdc++.h>
#define ALL(v) std::begin(v),std::end(v)
#define LOOP(k) for(i64 ngtkana_is_a_genius=0; ngtkana_is_a_genius<(i64)k; ngtkana_is_a_genius++)

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
template <usize N, class T, class... Args, std::enable_if_t<N==0, int> = 0>
auto mkvec(Args... args) {
    return T(args...);
}
template <usize N, class T, class... Args, std::enable_if_t<N!=0, int> = 0>
auto mkvec(usize sz, Args... args) {
    using value_type = std::decay_t<decltype(mkvec<N-1, T>(args...))>;
    return vec<value_type>(sz, mkvec<N-1, T>(args...));
}
int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::setprecision(15) << std::fixed;

    usize n, m;
    std::cin >> n >> m;
    auto g = mkvec<2, usize>(n, n);
    while (m--) {
        usize u, v;
        std::cin >> u >> v;
        u--, v--;
        g.at(u).at(v) = true;
        g.at(v).at(u) = true;
    }

    vec<usize> ord(n);
    std::iota(ALL(ord), usize{0});
    u32 ans = 0;
    do {
        bool ng = false;
        for (usize i=0; i<n-1; i++) {
            if (!g.at(ord.at(i)).at(ord.at(i+1))) {
                ng = true;
                break;
            }
        }
        ans += !ng;
    } while (std::next_permutation(ord.begin() + 1, ord.end()));

    std::cout << ans << '\n';
}
