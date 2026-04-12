#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
const int inf = 1e9 + 7;
const ll INF = 1e18;
int mod = 1000000007;
#define abs(x) (x >= 0 ? x : -(x))
#define lb(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define ub(v, x) (int)(upper_bound(all(v), x) - v.begin())
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
ll modpow(ll a, ll b, ll _mod) { return b ? modpow(a * a % _mod, b / 2, _mod) * (b % 2 ? a : 1) % _mod : 1; }
template<class T> ostream& operator << (ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }
template<class T, class U> ostream& operator << (ostream& os, const pair<T, U>& p) { os << p.F << " " << p.S; return os; }
template<typename T >inline istream& operator >> (istream& is, vector<T>& v) { rep(j, sz(v)) is >> v[j]; return is; }
template<class T> inline void add(T &a, int b) { a += b; if (a >= mod) a -= mod; }


void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);

    int T;
    // cin >> T;
    T = 1;

    while (T--) {
        solve();
    }
}

struct mint {
  ll x;
  mint (ll x = 0) : x(x >= 0 ? x % mod : (mod + x % mod) % mod) {}
  mint operator -() const { return mint(-x); }
  mint& operator += (const mint a) { // コンストラクタの、modで割った余りがくる
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator -= (const mint a) {
    if ((x += -a.x + mod) >= mod) x -= mod;
    return *this;
  }
  mint& operator *= (const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator + (const mint a) const {
    mint res(*this);
    return res += a; // ?
  }
  mint operator - (const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator * (const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const { // mint(a).pow(t) tは余りとったりしたらあかん
    if (t == 0) return 1;
    mint a = pow(t >> 1); // 再帰
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // 逆元
  mint inv() const {
    return pow(mod - 2);
  }
  mint& operator /= (const mint a) { // invを利用
    return (*this) *= a.inv();
  }
  mint operator / (const mint a) const {
    mint res(*this);
    return res /= a;
  }
  friend ostream &operator<<(ostream &s, mint a) { return s << a.x; }
};

const int MAX = 2000005;
ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
// 二項係数計算
ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

ll k;
mint calc(ll n, ll m) {
  mint tmp = COM(n * m - 1, k - 1);
  tmp *= k - 1;
  tmp *= n;

  rep3(i, 1, k + 1) {
    tmp -= (mint)COM(n, i) * COM(n * m - n, k - i) * 2 * COM(i, 2);
  }

  mint ans = 0;
  rep3(x, 1, m + 1) {
    ans += tmp * (x - 1) * modpow(m - 1, mod - 2, mod) * x;
    ans -= tmp * (m - x) * modpow(m - 1, mod - 2, mod) * x;
  }
  return ans;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  cin >> k;

  COMinit();
  mint ans = calc(n, m);
  ans += calc(m, n);
  cout << ans << endl;
}
