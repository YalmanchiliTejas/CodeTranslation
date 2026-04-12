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
#define endl codeforces
#define ALL(v) std::begin(v), std::end(v)
#define ALLR(v) std::rbegin(v), std::rend(v)
using ll = std::int64_t;
using ull = std::uint64_t;
using pii = std::pair<int, int>;
using tii = std::tuple<int, int, int>;
using pll = std::pair<ll, ll>;
using tll = std::tuple<ll, ll, ll>;
template <typename T> using vec = std::vector<T>;
template <typename T> using vvec = vec<vec<T>>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename T, typename... Tail> const T& var_min(const T &t, const Tail&... tail) { return std::min(t, var_min(tail...)); }
template <typename T, typename... Tail> const T& var_max(const T &t, const Tail&... tail) { return std::max(t, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
template <typename T> const T& clamp(const T &t, const T &low, const T &high) { return std::max(low, std::min(high, t)); }
template <typename T> void chclamp(T &t, const T &low, const T &high) { return t = clamp(t, low, high); }
template <typename T> T make_v(T init) { return init; }
template <typename T, typename... Tail> auto make_v(T init, std::size_t s, Tail... tail) { auto v = std::move(make_v(init, tail...)); return vec<decltype(v)>(s, v); }
template <typename T, std::size_t Head, std::size_t ...Tail> struct multi_dem_array { using type = std::array<typename multi_dem_array<T, Tail...>::type, Head>; };
template <typename T, std::size_t Head> struct multi_dem_array<T, Head> { using type = std::array<T, Head>; };
template <typename T, std::size_t ...Args> using mdarray = typename multi_dem_array<T, Args...>::type;
namespace init__ { struct InitIO { InitIO() { std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false); std::cout << std::fixed << std::setprecision(30); } } init_io; }

const ll inf = 5e15;

ll solve() {
    ll n;
    std::cin >> n;
    vec<ll> av(n);
    for (ll &e : av) std::cin >> e;

    std::map<pll, ll> dp;
    dp[pll(0, 0)] = 0;
    for (ll i = 1; i <= n; i++) {
        std::map<pll, ll> ndp;
        auto update_dp = [&](pll key, ll val) {
            auto ite = ndp.find(key);
            if (ite == ndp.end()) ndp[key] = val;
            else chmax(ite->second, val);
        };
        ll e = av[i - 1];
        ll nidx[] = { i / 2, i / 2 - 1, i / 2 - 2 };
        for (ll idx : nidx) {
            pll keys[] = { pll(idx, 0), pll(idx, 1) };
            for (pll key : keys) {
                auto ite = dp.find(key);
                if (ite == dp.end()) continue;
                ll a, b;
                std::tie(a, b) = key;
                update_dp(pll(a, 0), ite->second);
                if (b == 0) update_dp(pll(a + 1, 1), ite->second + e);
            }
        }
        dp = std::move(ndp);
    }

    ll ans = -inf;
    for (ll i = 0; i < 2; i++) {
        auto ite = dp.find(pll(n / 2, i));
        if (ite != dp.end()) chmax(ans, ite->second);
    }
    return ans;
}

int main() {
    std::cout << solve() << '\n';
    return 0;
}
