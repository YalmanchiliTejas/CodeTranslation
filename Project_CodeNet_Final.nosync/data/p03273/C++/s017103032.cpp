/* mytemplate.cpp {{{ */

/* header */
#include <bits/stdc++.h>
using namespace std;

/* rep */
#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) rep2(_, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, n) rep4(i, a, n, 1)
#define rep4(i, a, n, s) for (ll i = (a); i < (ll)(n); i += (s))
#define per(...) GET_MACRO(__VA_ARGS__, per4, per3, per2, per1)(__VA_ARGS__)
#define per1(a) per2(_, a)
#define per2(i, a) per3(i, a, 0)
#define per3(i, a, n) per4(i, a, n, 1)
#define per4(i, a, n, s) for (ll i = (a) - 1; i >= (ll)(n); i -= (s))
#define each(x, c) for(auto&& x : c)

/* short */
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define len(c) ((ll)(c).size())
#define temp_T template<typename T>
#define temp_TU template<typename T, typename U>

/* debug */
#define debug(x) {cerr << #x << " = " << (x) << "\n";}

/* alias */
temp_T using vec = vector<T>;
temp_T using heap = priority_queue<T>;
temp_T using minheap = priority_queue<T, vec<T>, greater<T>>;
using ll = long long;
using str = string;
using vi = vec<ll>;
using vvi = vec<vi>;
using vs = vec<str>;
using vb = vec<bool>;
using pii = pair<ll, ll>;
using vp = vec<pii>;

/* const */
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

/* function */
inline ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
inline ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
bool isPrime(ll n) {if (n < 2) return false; rep(i, 2, (sqrt(n) + 1)) {if (n % i == 0) return false;} return true;}
void eratosthenes(vb& primes) {rep(i, len(primes)) primes[i] = true; primes[0] = primes[1] = false; rep(i, len(primes) / 2 + 1) {if (primes[i]) {rep(j, i + i, len(primes), i) primes[j] = false;}}}
inline ll minMultiple(ll a, ll n) {return n * (a / n + (a % n == 0 ? 0 : 1));}
vi listDivisors(ll n) {vi divs; rep(i, 1, sqrt(n) + 1) {if (n % i == 0) {divs.pb(i); divs.pb(n / i);}} sort(all(divs)); return divs; }
map<ll, ll> primeFactorize(ll n) {map<ll, ll> prime_factors; ll m = n; rep(i, 2, sqrt(n) + 1) {if (m < 1) break; while (m % i == 0) {++prime_factors[i]; m /= i;}} if (m != 1) ++prime_factors[m]; return prime_factors;}
inline ll mod_add(ll a, ll b) {return (a + b) % MOD;}
inline ll mod_sub(ll a, ll b) {return (a + MOD - b) % MOD;}
inline ll mod_mul(ll a, ll b) {return ((a % MOD) * (b % MOD)) % MOD;}
ll mod_pow(ll x, ll y) {if (y == 0) return 1; else if (y == 1) return x % MOD; else if (y % 2 == 0) {ll val = mod_pow(x, (ll)(y / 2)); return mod_mul(val, val);} else {ll val = mod_pow(x, (ll)(y / 2)); return mod_mul(mod_mul(val, val), x);}}
ll mod_inv(ll x) {return mod_pow(x, MOD - 2);}
ll mod_div(ll a, ll b) {return mod_mul(a, mod_inv(b));}
ll fact(ll n) {return n == 0 ? 1 : mod_mul(n, fact(n - 1));}
ll comb(ll n, ll r) {return fact(n) / fact(n - r) / fact(r);}
temp_T inline bool chmax(T& a, const T b) {if (a < b) a = b; return a < b;}
temp_T inline bool chmin(T& a, const T b) {if (a > b) a = b; return a > b;}
template<typename T = ll> inline T in() {T x; cin >> x; return x;}
temp_T inline void print(const T& x) {cout << x << "\n";}
temp_T inline void print(const vector<T>& v) {rep(i, len(v)) cout << v[i] << (i != len(v) - 1 ? " " : "\n");}
temp_T inline void print(const vector<vector<T>>& vv) {rep(j, len(vv)) print(vv[j]);}
temp_TU inline void print(const pair<T, U>& p) {cout << p.fi << " " << p.se << "\n";}
temp_TU inline void print(const vector<pair<T, U>>& vp) {rep(i, len(vp)) print(vp[i]);}
temp_TU inline void print(const map<T, U>& d) {each(x, d) print(x);}

/* init */
struct Init {Init(){cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(10);}} init;

/* }}} */


//-----------------------------------------------------------------------------

int main() {
    ll H = in(), W = in();
    vec<vec<char>> A(H, vec<char>(W));
    rep(i, H) rep(j, W) A[i][j] = in<char>();
    vb row(H, false), col(W, false);
    rep(i, H) rep(j, W) if (A[i][j] == '#') {
        row[i] = true; col[j] = true;
    }
    rep(i, H) {
        if (row[i]) {
            rep(j, W) {
                if (col[j]) {
                    cout << A[i][j];
                }
            }
            cout << "\n";
        }
    }
}