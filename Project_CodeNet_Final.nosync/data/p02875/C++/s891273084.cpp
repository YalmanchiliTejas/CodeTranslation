#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define rep1(i,n) for (int i = 1; i <= int(n); i++)
#define repR(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = int(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#ifdef LOCAL
#define dump(...) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] ", my_dmp(#__VA_ARGS__, __VA_ARGS__)
void my_dmp(const char*) { cerr << endl; }
template <class T, class... U> void my_dmp(const char *s, T const& x, U const& ...y) { const char *o = "({[", *e = "]})"; for (int i = 0; *s != '\0'; cerr << *s++) { if (count(o,o+3,*s)) i++; if (count(e,e+3,*s)) i--; if (!i && *s == ',') break; } cerr << " = " << x; if (*s == ',') cerr << ", ", s++; my_dmp(s, y...); }
#else
#define dump(...)
#endif
using ll = long long;
using ld = long double;
#define int ll
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { os << "{"; for (auto const& x : v) os << " " << x; return os << " }"; }
template <class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct my_Init { my_Init() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } my_init;

template <class T, size_t d, class = typename enable_if<(d == 0)>::type> constexpr auto make_v(T const& x = {}) { return x; }
template <class T, size_t d, class... U, class = typename enable_if<(d > 0)>::type> constexpr auto make_v(size_t n, U... x) { auto val = make_v<T,d-1>(x...); return vector<decltype(val)>(n, move(val)); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
const ll INF = (1LL<<62)-1; // ~ 4.6e18
////////////////////////////////
//
using ll = long long;
template <int M> // m : prime
class modint {
    ll x;
    struct Table {
        // static const int Size = 1e6 + 10;
        static const int Size = 1e7 + 10;
        static_assert(Size <= M, "");
        ll fac[Size], finv[Size], inv[Size];
        Table() {
            fac[0] = fac[1] = finv[0] = finv[1] = inv[1] = 1;
            for (int i = 2; i < Size; i++) {
                fac[i] = fac[i-1]*i % M;
                inv[i] = M - inv[M%i]*(M/i) % M;
                finv[i] = finv[i-1]*inv[i] % M;
            }
        }
    };
    static const Table tab;
public:
    static modint fact(int n) { assert(0 <= n && n < Table::Size); return tab.fac[n]; }
    static modint finv(int n) { assert(0 <= n && n < Table::Size); return tab.finv[n]; }
    static modint C(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return fact(n)*finv(k)*finv(n-k);
    }
    static modint P(int n, int k) {
        assert(n >= 0 && k >= 0 && n >= k);
        return fact(n)*finv(n-k);
    }
public:
    modint(ll x = 0) : x((x%=M) < 0 ? x+M : x) { }
    ll val() const { return x; }
    bool operator==(modint rhs) const { return x == rhs.x; }
    bool operator!=(modint rhs) const { return x != rhs.x; }
    modint operator+() const { return *this; }
    modint operator-() const { return {M-x}; }
    modint& operator+=(modint rhs) { if ((x += rhs.x) >= M) x -= M; return *this; }
    modint& operator-=(modint rhs) { if ((x += M-rhs.x) >= M) x -= M; return *this; }
    modint& operator*=(modint rhs) { (x *= rhs.x) %= M; return *this; }
    modint operator+(modint rhs) const { return modint(*this) += rhs; }
    modint operator-(modint rhs) const { return modint(*this) -= rhs; }
    modint operator*(modint rhs) const { return modint(*this) *= rhs; }
    modint& operator/=(modint rhs) { return *this *= rhs.inv(); }
    modint operator/(modint rhs) const { return *this * rhs.inv(); }
    modint pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        modint v = *this, r = 1;
        for (; n > 0; n >>= 1, v *= v) if (n&1) r *= v;
        return r;
    }
    modint inv() const {
        assert(x != 0);
        ll t = 1, v = x, q, r;
        while (v >= Table::Size) {
            q = M / v; r = M % v;
            if (r * 2 < v) {
                t *= -q; t %= M; v = r;
            } else {
                t *= q + 1; t %= M; v -= r;
            }
        }
        return t * tab.inv[v] % M;
    }
};
template <int M> typename modint<M>::Table const modint<M>::tab;
template <int M> ostream& operator<<(ostream& os, modint<M> rhs) { return os << rhs.val(); }
template <int M> istream& operator>>(istream& is, modint<M> &rhs) { ll x; is >> x; rhs = x; return is; }

constexpr int MOD = 998244353;
using mint = modint<MOD>;
//


int32_t main() {
    int n; cin >> n;
    mint ans = mint(3).pow(n);
    loop (k,n/2+1,<=n) ans -= mint::C(n,k)*mint(2).pow(n-k+1);
    cout << ans << endl;
}
