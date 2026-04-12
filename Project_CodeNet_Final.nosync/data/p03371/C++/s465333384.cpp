#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vs = vector<string>;
using vp = vector<pii>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(c) (ll)((c).size())
#define all(c) (c).begin(), (c).end()
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) rep2(_, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, n) rep4(i, a, n, 1)
#define rep4(i, a, n, s) for (ll i = (a), i##_len = (n); i < i##_len; i += (s))
#define per(...) overload4(__VA_ARGS__, per4, per3, per2, per1)(__VA_ARGS__)
#define per1(a) per2(_, a)
#define per2(i, a) per3(i, a, 0)
#define per3(i, a, n) per4(i, a, n, 1)
#define per4(i, a, n, s) for (ll i = (a) - 1, i##_len = (n); i >= i##_len; i -= (s))
#define each(x, c) for (auto&& (x) : (c))
#define debug(x) cerr << #x << " = " << (x) << endl;
const int INF = (1 << 30) - 1;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
inline ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
inline ll lcm(ll a, ll b) {return a * b / gcd(a, b);}
inline ll minMult(ll x, ll n) {return n * (x / n + (x % n == 0 ? 0 : 1));}
vi digits(ll n) {vi d; while(n) {d.pb(n % 10); n /= 10;} reverse(all(d)); return d;}
bool isPrime(ll n) {if (n < 2) return false; rep(i, 2, (sqrt(n) + 1)) {if (n % i == 0) return false;} return true;}
void eratosthenes(vb& primes) {rep(i, sz(primes)) primes[i] = true; primes[0] = primes[1] = false; rep(i, sz(primes) / 2 + 1) {if (primes[i]) {rep(j, i + i, sz(primes), i) primes[j] = false;}}}
vi listDivisors(ll n) {vi divs; rep(i, 1, sqrt(n) + 1) {if (n % i == 0) {divs.pb(i); divs.pb(n / i);}} sort(all(divs)); return divs;}
map<ll, ll> primeFactorize(ll n) {map<ll, ll> prime_factors; ll m = n; rep(i, 2, sqrt(n) + 1) {if (m < 1) break; while (m % i == 0) {++prime_factors[i]; m /= i;}} if (m != 1) ++prime_factors[m]; return prime_factors;}
inline ll mod_add(ll a, ll b) {return (a + b) % MOD;}
inline ll mod_sub(ll a, ll b) {return (a + MOD - b) % MOD;}
inline ll mod_mul(ll a, ll b) {return ((a % MOD) * (b % MOD)) % MOD;}
ll mod_pow(ll x, ll y) {if (y == 0) return 1; else if (y == 1) return x % MOD; else if (y % 2 == 0) {ll val = mod_pow(x, (ll)(y / 2)); return mod_mul(val, val);} else {ll val = mod_pow(x, (ll)(y / 2)); return mod_mul(mod_mul(val, val), x);}}
ll mod_inv(ll x) {return mod_pow(x, MOD - 2);}
ll mod_div(ll a, ll b) {return mod_mul(a, mod_inv(b));}
ll fact(ll n) {return n == 0 ? 1 : mod_mul(n, fact(n - 1));}
ll comb(ll n, ll r) {return fact(n) / fact(n - r) / fact(r);}
template<typename T> inline bool chmax(T& a, const T b) {if (a < b) a = b; return a < b;}
template<typename T> inline bool chmin(T& a, const T b) {if (a > b) a = b; return a > b;}
template<typename T> inline void print(const T& x) {cout << x << "\n";}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) {is >> p.fi >> p.se; return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {os << p.fi << " " << p.se; return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v) {each(in, v) is >> in; return is;}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {rep(i, sz(v)) {os << v[i] << (i + 1!= sz(v) ? " " : "");} return os;}
struct Init {Init() {cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(10);}} init;

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll mi = INF;
    rep(i, 10e5+1) {
        ll p = i * 2 * C + max((ll)0, X - i) * A + max((ll)0, Y - i) * B;
        chmin(mi, p);
    }
    print(mi);
}