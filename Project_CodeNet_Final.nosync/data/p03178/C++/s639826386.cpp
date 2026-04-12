// {{{ TEMPLATES
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
#define say(x) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] " << x << endl;
void my_dmp(const char*) { cerr << endl; }
template <class T, class... U> void my_dmp(const char *s, T const& x, U const& ...y) { const char *o = "({[", *e = "]})"; for (int i = 0; *s != '\0'; cerr << *s++) { if (count(o,o+3,*s)) i++; if (count(e,e+3,*s)) i--; if (!i && *s == ',') break; } cerr << " = " << x; if (*s == ',') cerr << ", ", s++; my_dmp(s, y...); }
#else
#define dump(...)
#define say(x)
#endif
using ll = long long;
using ld = long double;
#define int ll
#define double ld
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { os << "{"; for (auto const& x : v) os << " " << x; return os << " }"; }
template <class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
template <size_t i, class T> typename enable_if<i >= tuple_size<T>::value>::type output_tuple(ostream&, T const&) { }
template <size_t i = 0, class T> typename enable_if<i < tuple_size<T>::value>::type
output_tuple(ostream& os, T const& t) { os << (i ? " " : "") << get<i>(t); output_tuple<i+1,T>(os,t); }
template <class... T> ostream& operator<<(ostream& os, tuple<T...> const& t) { return output_tuple(os,t), os; }
struct my_Init { my_Init() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } my_init;
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
const ll INF = (1LL<<62)-1; // ~ 4.6e18
// }}}
///////////////////////////////
//
using ll = long long;
template <int M> // m : prime
class modint {
    static_assert(M > 0, "");
    ll x;
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
        while (v != 1) {
            q = M / v; r = M % v;
            if (r * 2 < v) {
                t *= -q; t %= M; v = r;
            } else {
                t *= q + 1; t %= M; v -= r;
            }
        }
        return t;
    }
};
template <int M> ostream& operator<<(ostream& os, modint<M> rhs) { return os << rhs.val(); }
template <int M> istream& operator>>(istream& is, modint<M> &rhs) { ll x; is >> x; rhs = x; return is; }

//constexpr int MOD = 998244353;
constexpr int MOD = 1e9+7;
using mint = modint<MOD>;
//

int mod(ll x, ll m) { return (x%=m) < 0 ? x+m : x; }


int32_t main() {
    string s; cin >> s;
    int d; cin >> d;
    int n = s.size();

    const int NN = n+5;
    vec<mint,2> dp = make_v<mint,2>(NN,d);
    dp[0][0] = 1;
    rep (i,NN-1) {
        rep (j,d) rep (k,10) dp[i+1][mod(j+k,d)] += dp[i][j];
    }
    mint ans = 0;
    int sum = 0;
    rep (i,n) {
        int x = s[i]-'0';
        rep (j,x) {
            ans += dp[n-i-1][mod(-sum-j,d)];
        }
        sum = mod(sum+x,d);
    }
    if (sum == 0) ans += 1;
    cout << ans-1 << endl;
}
