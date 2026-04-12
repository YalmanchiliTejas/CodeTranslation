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

const ll mod = 1e9 + 7;
using mint = math::Modint<mod>;
const std::size_t SIZE = 110;
mint dp[SIZE][SIZE];

struct Compress {
    vec<ll> v;

    Compress(const vec<ll> &v_) : v(v_) {
        v.push_back(0);
        std::sort(ALL(v));
        auto ite = std::unique(ALL(v));
        v.erase(ite, v.end());
    }

    ll get_id(ll n) {
        return std::distance(v.begin(),
                             std::lower_bound(ALL(v), n));
    }
};

int main() {
    ll n;
    std::cin >> n;
    vec<ll> h(n);
    for (ll &e : h) std::cin >> e;

    Compress cmp(h);
    
    ll phid = cmp.get_id(h[0]);
    dp[1][0] = (math::pow(mint(2), cmp.v[1]) - 2) * math::pow(mint(2), h[0] - cmp.v[1]);
    for (ll i = 1; i < phid; i++) dp[1][i] = (math::pow(mint(2), cmp.v[i + 1] - cmp.v[i]) - 1) * 2 * math::pow(mint(2), cmp.v[phid] - cmp.v[i + 1]);
    dp[1][phid] = 2;
    for (ll i = 1; i < n; i++) {
        ll hid = cmp.get_id(h[i]);
        if (hid <= phid) {
            for (ll h = 0; h < hid; h++) dp[i + 1][h] = dp[i][h];
            for (ll h = hid; h <= phid; h++) dp[i + 1][hid] += dp[i][h];
            dp[i + 1][hid] *= 2;
        } else {
            ll diff = h[i] - h[i - 1];
            mint pow2 = math::pow(mint(2), diff);
            for (ll h = 0; h < phid; h++) dp[i + 1][h] = dp[i][h] * pow2; 
            for (ll h = phid; h < hid; h++) {
                ll diff1 = cmp.v[hid] - cmp.v[h + 1];
                ll diff2 = cmp.v[h + 1] - cmp.v[h];
                dp[i + 1][h] = (math::pow(mint(2), diff2) - 1) * math::pow(mint(2), diff1) * dp[i][phid] * 2;
            }
            dp[i + 1][hid] = dp[i][phid] * 2;
        }
        phid = hid;
    }

    mint ans = 0;
    for (ll i = 0; i < SIZE; i++) ans += dp[n][i];
    std::cout << ans.value() << '\n';
    return 0;
}
