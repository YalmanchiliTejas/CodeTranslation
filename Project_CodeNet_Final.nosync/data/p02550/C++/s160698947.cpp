#define CPP17
#include <limits>
#include <initializer_list>
#include <utility>
#include <bitset>
#include <tuple>
#include <type_traits>
#include <functional>
#include <string>
#include <array>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <algorithm>
#include <complex>
#include <random>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <regex>
#include <cassert>
#include <cstddef>
#ifdef CPP17
#include <variant>
#endif

#define endl codeforces

#define ALL(v) std::begin(v), std::end(v)
#define ALLR(v) std::rbegin(v), std::rend(v)

using ll = std::int64_t;
using ull = std::uint64_t;
using pii = std::pair<int, int>;
using tii = std::tuple<int, int, int>;
using pll = std::pair<ll, ll>;
using tll = std::tuple<ll, ll, ll>;
using size_type = ssize_t;
template <typename T> using vec = std::vector<T>;
template <typename T> using vvec = vec<vec<T>>;

template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return std::min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return std::max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }

template <typename T, std::size_t Head, std::size_t... Tail> 
struct multi_dim_array { using type = std::array<typename multi_dim_array<T, Tail...>::type, Head>; };

template <typename T, std::size_t Head> 
struct multi_dim_array<T, Head> { using type = std::array<T, Head>; };

template <typename T, std::size_t... Args> using mdarray = typename multi_dim_array<T, Args...>::type;

#ifdef CPP17
template <typename T, typename F, typename... Args> 
void fill_seq(T &t, F f, Args... args) { 
    if constexpr (std::is_invocable<F, Args...>::value) { 
        t = f(args...); 
    } else { 
        for (size_type i = 0; i < t.size(); i++) fill_seq(t[i], f, args..., i); 
    } 
}
#endif

template <typename T> vec<T> make_v(size_type sz) { return vec<T>(sz); }

template <typename T, typename... Tail> 
auto make_v(size_type hs, Tail&&... ts) { 
    auto v = std::move(make_v<T>(std::forward<Tail>(ts)...)); 
    return vec<decltype(v)>(hs, v); 
}

namespace init__ { 
struct InitIO { 
    InitIO() { 
        std::cin.tie(nullptr); 
        std::ios_base::sync_with_stdio(false); 
        std::cout << std::fixed << std::setprecision(30); 
    } 
} init_io; 
}
template <typename T>
T ceil_pow2(T bound) {
    T ret = 1;
    while (ret < bound) ret *= 2;
    return ret;
}
template <typename T>
T ceil_div(T a, T b) { return a / b + !!(a % b); }
#define CPP17

   
int main() {
    ll n, x, m;
    std::cin >> n >> x >> m;
    vec<ll> used(m, -1);
    vec<ll> sum(m + 3, 0);
    ll cur = x;
    ll ans = cur;
    sum[1] += cur;
    used[cur] = 0;
    for (ll i = 1; i < n; i++) {
        ll nxt = (cur * cur) % m;
        sum[i + 1] = sum[i] + nxt;
        if (used[nxt] != -1) {
            ll fst = used[nxt];
            ll len = i - fst;
            ans = sum[i + 1];
            ll diff = sum[i + 1] - sum[fst + 1];
            ll rest = n - i;
            ans += diff * (rest / len);
            rest %= len;
            ans += sum[fst + rest] - sum[fst + 1];
            break;
        }
        ans = sum[i + 1];
        cur = nxt;
        used[cur] = i;
    }

    std::cout << ans << "\n";
    return 0;
}
