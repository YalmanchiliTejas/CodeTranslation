// >>> TEMPLATES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int ll
#define double ld
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define repR(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = (int)(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define INF (numeric_limits<int>::max()/2-1)
#ifdef LOCAL
#include "debug.hpp"
#define dump(...) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] ", dump_impl(#__VA_ARGS__, __VA_ARGS__)
#define say(x) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] " << x << endl
#define debug if (1)
#else
#define dump(...) (void)(0)
#define say(x) (void)(0)
#define debug if (0)
#endif
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { bool f = true; for (auto const& x : v) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint {
    template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); }
};
#define MFP MakeFixPoint()|
#define def(name, ...) auto name = MFP [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) {
    return lower_bound(v.begin(), v.end(), x)-v.begin();
}
template <class C, class T> int ubd(C const& v, T const& x) {
    return upper_bound(v.begin(), v.end(), x)-v.begin();
}
// <<<
// >>> modint
template <int32_t md>
class modint {
    static_assert(md > 0, "");
    using M = modint;
    using ll = int64_t;
    int32_t x;
public:
    static constexpr int32_t mod = md;
    constexpr modint(ll x = 0) : x((x%=mod) < 0 ? x+mod : x) { }
    constexpr ll val() const { return x; }
    constexpr operator ll() const { return x; }
    constexpr bool operator==(M const& r) const { return x == r.x; }
    constexpr bool operator!=(M const& r) const { return x != r.x; }
    constexpr M operator+() const { return *this; }
    constexpr M operator-() const { return M()-*this; }
    constexpr M& operator+=(M const& r) { ll t = ll(x) + r.x; if (t >= mod) t -= mod; x = t; return *this; }
    constexpr M& operator-=(M const& r) { ll t = ll(x) + mod-r.x; if (t >= mod) t -= mod; x = t; return *this; }
    constexpr M& operator*=(M const& r) { return *this = *this * r; }
    constexpr M operator*(M const& r) const { M t; t.x = (ll(x)*r.x) % mod; return t; }
    constexpr M& operator/=(M const& r) { return *this *= r.inv(); }
    constexpr M operator+(M const& r) const { return M(*this) += r; }
    constexpr M operator-(M const& r) const { return M(*this) -= r; }
    constexpr M operator/(M const& r) const { return M(*this) /= r; }
    friend constexpr M operator+(ll x, M const& y) { return M(x)+y; }
    friend constexpr M operator-(ll x, M const& y) { return M(x)-y; }
    friend constexpr M operator*(ll x, M const& y) { return M(x)*y; }
    friend constexpr M operator/(ll x, M const& y) { return M(x)/y; }
    constexpr M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M v = *this, r = 1;
        for (; n > 0; n >>= 1, v *= v) if (n&1) r *= v;
        return r;
    }
    constexpr M inv() const {
        assert(x > 0);
        ll t = 1, v = x, q = 0, r = 0;
        while (v != 1) {
            q = mod / v; r = mod % v;
            if (r * 2 < v) {
                t *= -q; t %= mod; v = r;
            } else {
                t *= q + 1; t %= mod; v -= r;
            }
        }
        if (t < 0) t += mod;
        M y; y.x = t; return y;
    }
#ifdef LOCAL
    friend string to_s(M r) { return to_s(r.val(), mod); }
#endif
    friend ostream& operator<<(ostream& os, M r) { return os << r.val(); }
    friend istream& operator>>(istream& is, M &r) { int64_t x; is >> x; r = x; return is; }
};
// <<<
//constexpr int64_t MOD = 998244353;
constexpr int64_t MOD = 1e9+7;
using mint = modint<(int32_t)MOD>;
// >>> mod table
template <int32_t mod>
struct ModTable {
    static constexpr int32_t Size = 1e6 + 10;
    static_assert(Size <= mod, "");
    using ll = int64_t;
    int32_t fact[Size], finv[Size], inv[Size];
    ModTable() {
        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] = 1;
        for (int i = 2; i < Size; i++) {
            fact[i] = ll(fact[i-1])*i % mod;
            inv[i] = mod - ll(inv[mod%i])*(mod/i) % mod;
            finv[i] = ll(finv[i-1])*inv[i] % mod;
        }
    }
};
const ModTable<MOD> mod_tab;

modint<MOD> fact(int n) {
    assert(0 <= n); assert(n < ModTable<MOD>::Size);
    return mod_tab.fact[n];
}
modint<MOD> finv(int n) {
    assert(0 <= n); assert(n < ModTable<MOD>::Size);
    return mod_tab.finv[n];
}
modint<MOD> C(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact(n)*finv(k)*finv(n-k);
}
modint<MOD> P(int n, int k) {
    assert(k >= 0);
    return fact(n)*finv(n-k);
}
// <<<

int32_t main() {
    int n,a,b,c,d; cin >> n >> a >> b >> c >> d;

    vector<mint> dp(n+1);
    dp[0] = 1;
    loop (i,a,<=b) {
        auto tmp = dp;
        rep (j,sz(dp)) {
            for (int k = c; k <= d; ++k) {
                int jj = j-k*i;
                if (jj < 0) break;
                tmp[j] += dp[jj] * P(j,k*i) / (fact(i).pow(k) * fact(k));
            }
        }
        swap(tmp,dp);
    }

    cout << dp[n] << endl;
}
