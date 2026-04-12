#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define double long double
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep1(i,n) for (int i=1; i<(int)(n); ++i)
#define repeq(i,n) for (int i=0; i<=(int)(n); ++i)
#define rep1eq(i,n) for (int i=1; i<=(int)(n); ++i)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; --i)
#define rrep1(i,n) for (int i=(int)(n)-1; i>0; --i)
#define rrepeq(i,n) for (int i=(int)(n); i>=0; --i)
#define rrep1eq(i,n) for (int i=(int)(n); i>0; --i)
#define REP(i,a,b) for (int i=(int)(a); i<=(int)(b); ++i)
#define RREP(i,a,b) for (int i=(int)(a); i>=(int)(b); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
template<typename T> using Graph = vector<vector<T>>;
template<typename T> using Spacial = vector<vector<vector<T>>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T> using greater_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD = 1e9+7;
const int MOD2 = 998244353;
// const double EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
string interval[2] = {" ", "\n"}; // {" ", "\n"}

template<typename T> struct is_plural : false_type{};
template<typename T1, typename T2> struct is_plural<pair<T1, T2>> : true_type{};
template<typename T> struct is_plural<vector<T>> : true_type{};
template<typename T> struct is_plural<complex<T>> : true_type{};
 
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << " " << p.second; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto itr = vec.begin(); itr != vec.end(); ++itr) is >> *itr; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { if (vec.empty()) return os; bool pl = is_plural<T>(); os << vec.front(); for (auto itr = ++vec.begin(); itr != vec.end(); ++itr) os << interval[pl] << *itr; return os; }
 
bool CoutYN(bool a, string y = "Yes", string n = "No") { cout << (a ? y : n) << "\n"; return a; }

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

long long modpow(int a, long long n, int mod = MOD) { long long ret = 1; do { if (n & 1) ret = ret * a % mod; a = 1LL * a * a % mod; } while (n >>= 1); return ret; }

template<typename T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }

template<typename T1, typename T2> bool CompareBySecond(pair<T1, T2> a, pair<T1, T2> b) { return a.second != b.second ? a.second < b.second : a.first < b.first; }
template<typename T1, typename T2> bool CompareByInverse(pair<T1, T2> a, pair<T1, T2> b) { return a.first != b.first ? a.first < b.first : a.second > b.second; }


/* -------- <templates end> -------- */


struct Combination {
  vector<long long> fac, finv, inv;
  const int mod;

  Combination(int MAX, int mod = MOD) : fac(MAX + 1), finv(MAX + 1), inv(MAX + 1), mod(mod) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<=MAX; ++i) {
      fac[i] = fac[i-1] * i % mod;
      inv[i] = mod - inv[mod%i] * (mod/i) % mod;
      finv[i] = finv[i-1] * inv[i] % mod;
    }
  }

  long long P(int n, int r) const {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[n-r] % mod;
  }

  long long C(int n, int r) const {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n-r] % mod) % mod;
  }

  long long H(int n, int r) const {
    if (n < 0 || r < 0) return 0;
    return C(n + r - 1, r);
  }
};

void solve() {
  int n, m; cin >> n >> m;

  Combination comb(n, m);

  Graph<ll> mpw(n+1, vl(n+1, 1));
  rep1eq(i,n) {
    ll &base = mpw[i][1] = mpw[i-1][1] * 2 % m;
    REP(j,2,n) {
      mpw[i][j] = mpw[i][j-1] * base % m;
    }
  }

  vl calc(n+1);
  calc[0] = 2;
  rep(i,n) calc[i+1] = calc[i] * calc[i] % m;

  Graph<ll> dp(n+1, vl(n+1, 0));
  dp[0][0] = 1;

  rep(i,n) {
    repeq(j,i) {
      (dp[i+1][j] += dp[i][j] * (j+1)) %= m;
      (dp[i+1][j+1] += dp[i][j]) %= m;
    }
  }

  ll ans = calc[n];
  
  rep1eq(i,n) {
    repeq(j,i) {
      if (i & 1) ans -= comb.C(n, i) * (calc[n-i] * (dp[i][j] * mpw[n-i][j] % m) % m) % m;
      else ans += comb.C(n, i) * (calc[n-i] * (dp[i][j] * mpw[n-i][j] % m) % m) % m;
    }
  }

  ans %= m;
  if (ans < 0) ans += m;
  cout << ans << endl;
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
