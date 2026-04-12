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


namespace math {

template <typename T>
constexpr T pow(const T &n, ll k) {
    T ret = n.mul_id_ele();
    T cur = n;
    while (k) {
        if (k & 1) ret *= cur;
        cur *= cur;
        k /= 2;
    }
    return ret;
}

}

namespace math {

template <ll Mod>
struct Modint {

    constexpr Modint(ll x) noexcept : x(static_cast<ll>((Mod + x % Mod) % Mod)) { }
    
    constexpr Modint() noexcept : Modint(0) { }
    
    constexpr Modint<Mod> add_id_ele() const noexcept { 
        return Modint<Mod>(0); 
    }
    
    constexpr Modint<Mod> mul_id_ele() const noexcept {
        return Modint<Mod>(1); 
    }
    
    constexpr ll value() const noexcept {
        return static_cast<ll>(x); 
    }

    constexpr Modint& operator+=(const Modint &oth) noexcept {
        x += oth.value();
        if (Mod <= x) x -= Mod;
        return *this;
    }

    constexpr Modint& operator-=(const Modint &oth) noexcept {
        x += Mod - oth.value();
        if (Mod <= x) x -= Mod;
        return *this;
    }

    constexpr Modint& operator*=(const Modint &oth) noexcept {
        x *= oth.value();
        x %= Mod;
        return *this;
    }

    constexpr Modint& operator/=(const Modint &oth) noexcept {
        x *= oth.inv().value();
        x %= Mod;
        return *this;
    }

    constexpr Modint operator+(const Modint &oth) const noexcept {
        return Modint(x) += oth;
    }

    constexpr Modint operator-(const Modint &oth) const noexcept {
        return Modint(x) -= oth;
    }

    constexpr Modint operator*(const Modint &oth) const noexcept {
        return Modint(x) *= oth;
    }

    constexpr Modint operator/(const Modint &oth) const noexcept {
        return Modint(x) /= oth;
    }

    constexpr Modint operator-() const noexcept {
        return Modint((x != 0) * (Mod - x)); 
    }

    constexpr bool operator==(const Modint &oth) const noexcept {
        return value() == oth.value();
    }

    template <typename T>
    constexpr typename std::enable_if<std::is_integral<T>::value, const Modint&>::type
    operator=(T t) noexcept {
        (*this) = Modint(std::forward<T>(t)); 
        return *this;
    }

    constexpr Modint inv() const noexcept {
        return ::math::pow(*this, Mod - 2);
    }

    constexpr ll mod() const noexcept {
        return static_cast<ll>(Mod);
    }

private:
    ll x;
};

template <ll Mod>
Modint<Mod> inv(Modint<Mod> m) {
    m.inv();
    return m;
}

template <ll Mod>
std::istream& operator>>(std::istream &is, Modint<Mod> &m) {
    ll v;
    is >> v;
    m = v;
    return is;
}

template <ll Mod>
std::ostream& operator<<(std::ostream &os, Modint<Mod> m) {
    os << m.value();
    return os;
}

}

int main() {
    constexpr ll mod = 1e9 + 7;
    using mint = math::Modint<mod>;
    ll n;
    std::cin >> n;
    vec<mint> av(n);
    for (auto &&e : av) std::cin >> e;
    mint sum = 0, sum2 = 0;
    for (auto e : av) {
        sum += e;
        sum2 += e * e;
    }
    sum *= sum;
    sum -= sum2;
    sum /= 2;
    std::cout << sum << "\n";
    return 0;
}
