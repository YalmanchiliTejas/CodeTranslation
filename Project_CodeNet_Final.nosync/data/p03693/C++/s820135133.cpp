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

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::setprecision(15) << std::fixed;

    u32 x = 0, coeff = 100;
    for (usize i=0; i<3; i++, coeff/=10) {
        u32 y;
        std::cin >> y;
        x += coeff * y;
    }
    std::cout << (x % 4 == 0 ? "YES" : "NO") << '\n';
}
