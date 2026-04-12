#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for (int i = (int)l; i < (int)(r); ++(i))
#define rrange(i, l, r) for (int i = ((int)(r) - 1); i >= (int)l; --(i))

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rwhole(f,x,...) ([&](decltype((x)) whole) { return (f)(rbegin(whole), rend(whole), ## __VA_ARGS__); })(x)

#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

inline void br(ostream &os = cerr) { os << endl; }

using int32 = int;
using int64 = long long;

const int mod     = 1e9 + 7;
const int32 inf   = 1001001001;
const int64 infll = 1001001001001001001ll;

const int dx[] = {0, -1, 1, 0, -1, 1, -1, 1}, dy[] = {-1, 0, 0, 1, -1, -1, 1, 1};
const string YES = "YES", NO = "NO", Yes = "Yes", No = "No", yes = "yes", no = "no";

struct IoSetup { IoSetup(){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;

template <typename T = int64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; } 
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << p.fs << " " << p.sc; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.fs >> p.sc; return is; }

template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// clang-format on

template< int mod >
struct ModInt
{
  int x;

  ModInt() : x(0) {}

  ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p)
  {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p)
  {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p)
  {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p)
  {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const
  {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return ModInt(u);
  }

  friend ostream &operator<<(ostream &os, const ModInt< mod > &p)
  {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt< mod > &a)
  {
    long long x;
    is >> x;
    a = ModInt< mod >(x);
    return (is);
  }

};

using modint = ModInt< mod >;

template< int mod >
struct Combination
{
  vector< int64_t > mfact, rfact;

  Combination(int sz) : mfact(sz + 1), rfact(sz + 1)
  {
    mfact[0] = 1;
    for(int i = 1; i < mfact.size(); i++) {
      mfact[i] = mfact[i - 1] * i % mod;
    }
    rfact[sz] = inv(mfact[sz]);
    for(int i = sz - 1; i >= 0; i--) {
      rfact[i] = rfact[i + 1] * (i + 1) % mod;
    }
  }

  int64_t fact(int k) const
  {
    return (mfact[k]);
  }

  int64_t pow(int64_t x, int64_t n) const
  {
    int64_t ret = 1;
    while(n > 0) {
      if(n & 1) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return (ret);
  }

  int64_t inv(int64_t x) const
  {
    return (pow(x, mod - 2));
  }

  int64_t P(int n, int r) const
  {
    if(r < 0 || n < r) return (0);
    return (mfact[n] * rfact[n - r] % mod);
  }

  int64_t C(int p, int q) const
  {
    if(q < 0 || p < q) return (0);
    return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);
  }

  int64_t H(int n, int r) const
  {
    if(n < 0 || r < 0) return (0);
    return (r == 0 ? 1 : C(n + r - 1, r));
  }
};

void solver() {
  int N = input(), A = input(), B = input(), C = input(), D = input();

  vector<modint> dp(N + 1);
  dp[N] = 1;

  Combination<mod> mC(N);

  range(i, A, B + 1) {
    range(j, 0, N + 1) {
      modint rev = 1;

      range(k, 1, D + 1) {
        if (j < i * k) break;

        rev *= mC.rfact[i];
        if (C <= k && k <= D) {
          dp[j - k * i] += dp[j] * rev * mC.rfact[k];
        } 
      }
    }
  }

  cout << dp[0] * mC.fact(N) << endl;
}

signed main(int argc, char *argv[]) {
  solver();
}