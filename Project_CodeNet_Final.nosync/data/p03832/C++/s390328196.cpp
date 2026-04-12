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


template<uint_fast64_t Modulus = MOD>
struct Modint {
  using u64 = uint_fast64_t;
  u64 a;

  constexpr Modint(const u64 x = 0) noexcept : a(x % Modulus) {}

  constexpr Modint operator+(const Modint rhs) const noexcept {
    return Modint(*this) += rhs;
  }
  constexpr Modint operator-(const Modint rhs) const noexcept {
    return Modint(*this) -= rhs;
  }
  constexpr Modint operator*(const Modint rhs) const noexcept {
    return Modint(*this) *= rhs;
  }
  constexpr Modint operator/(const Modint rhs) const noexcept {
    return Modint(*this) /= rhs;
  }

  constexpr Modint &operator+=(const Modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) a -= Modulus;
    return *this;
  }
  constexpr Modint &operator-=(const Modint rhs) noexcept {
    if (a < rhs.a) a += Modulus;
    a -= rhs.a;
    return *this;
  }
  constexpr Modint &operator*=(const Modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr Modint &operator/=(Modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp & 1) *this *= rhs;
      rhs *= rhs;
      exp >>= 1;
    }
    return *this;
  }

  Modint pow(u64 t) const {
    if (!t) return 1;
    Modint x = pow(t>>1);
    x *= x;
    if (t&1) x *= *this;
    return x;
  }

  explicit operator bool() const {
    return a;
  }

  friend ostream &operator<<(ostream &os, const Modint &m) {
    return os << m.a;
  }
};

using mint = Modint<>;

template<typename T>
struct ModCombination {
  vector<T> fac, finv, inv;

  ModCombination(int MAX) : fac(MAX + 1), finv(MAX + 1), inv(MAX + 1) {
    fac[0] = finv[MAX] = inv[0] = 1;
    for (int i=1; i<=MAX; ++i) fac[i] = fac[i-1] * i;
    finv[MAX] /= fac[MAX];
    for (int i=MAX-1; i>=0; --i) finv[i] = finv[i+1] * (i+1);
    for (int i=1; i<=MAX; ++i) inv[i] = finv[i] * fac[i-1];
  }

  T P(int n, int r) const {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[n-r];
  }

  T C(int n, int r) const {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] * finv[n-r];
  }

  T H(int n, int r) const {
    if (n < 0 || r < 0) return 0;
    return C(n + r - 1, r);
  }
};

void solve() {
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

  ModCombination<mint> comb(n);

  vector<mint> dp(n+1, 0);
  dp[n] = 1;

  REP(x,a,b) {
    repeq(i,n) if (dp[i]) {
      mint tmp = comb.P(i, c * x) / comb.P(x, x).pow(c) / comb.P(c, c);
      REP(j,c,d) {
        int to = i - j * x;
        if (to < 0) break;
        dp[to] += dp[i] * tmp;
        tmp *= comb.C(to, x) / (j + 1);
      }
    }
  }

  cout << dp[0] << endl;
}


/* -------- <programs end> -------- */


signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
