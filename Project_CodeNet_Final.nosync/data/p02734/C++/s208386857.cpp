#include <bits/stdc++.h>
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

    constexpr Modint(ll x) : x((Mod + x % Mod) % Mod) { }
    
    constexpr Modint() : Modint(0) { }
    
    constexpr Modint<Mod> add_id_ele() const { 
        return Modint<Mod>(0); 
    }
    
    constexpr Modint<Mod> mul_id_ele() const {
        return Modint<Mod>(1); 
    }
    
    constexpr ll& value() { 
        return x; 
    }
    
    constexpr ll value() const {
        return x; 
    }

    constexpr Modint& operator +=(const Modint &oth) {
        x += oth.value();
        if (Mod <= x) x -= Mod;
        return *this;
    }

    constexpr Modint& operator -=(const Modint &oth) {
        x += Mod - oth.value();
        if (Mod <= x) x -= Mod;
        return *this;
    }

    constexpr Modint& operator *=(const Modint &oth) {
        x *= oth.value();
        x %= Mod;
        return *this;
    }

    constexpr Modint& operator /=(const Modint &oth) {
        x *= oth.inv();
        x %= Mod;
        return *this;
    }

    constexpr Modint operator +(const Modint &oth) const {
        return Modint(x) += oth;
    }

    constexpr Modint operator -(const Modint &oth) const {
        return Modint(x) -= oth;
    }

    constexpr Modint operator *(const Modint &oth) const {
        return Modint(x) *= oth;
    }

    constexpr Modint operator /(const Modint &oth) const {
        return Modint(x) /= oth;
    }

    constexpr Modint operator -() const {
        return Modint((x != 0) * (Mod - x)); 
    }

    template <typename T>
    constexpr typename std::enable_if<std::is_integral<T>::value, const Modint&>::type
    operator =(T t) {
        (*this) = Modint(std::forward<T>(t)); 
        return *this;
    }

    constexpr Modint inv() const {
        return ::math::pow(*this, Mod - 2);
    }

    constexpr ll mod() const {
        return Mod;
    }

private:
    ll x;
};

}

const ll mod = 998244353;
const std::size_t SIZE = 3010;
using mint = math::Modint<mod>;
std::array<mint, SIZE> dp;

int main() {
    ll n, s;
    std::cin >> n >> s;
    vec<ll> a(n);
    for (ll &e : a) std::cin >> e;
    mint ans = 0;
    for (ll i = 0; i < n; i++) {
        ll e = a[i];
        for (ll j = s - 1; 0 <= j; j--) if (j + e <= s) dp[j + e] += dp[j];
        dp[e] += (i + 1);
        ans += dp[s];
    }

    std::cout << ans.value() << '\n';
    return 0;
}
