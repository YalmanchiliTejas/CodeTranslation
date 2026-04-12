#include <bits/stdc++.h>

#if MYDEBUG
#include "lib/cp_debug.hpp"
#else
#define DBG(...) ;
#endif
#if __cplusplus <= 201402L
template <typename T>
T gcd(T a, T b) { return ((a % b == 0) ? b : gcd(b, a % b)); }
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }
#endif
using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 1E9 + 7;

namespace Problem {
using namespace std;
template <long long Mod = MOD>
class Modint {
 public:
  long long v;

  Modint(const Modint &x) { v = x.v; }
  explicit Modint(int x) {
    if (x < 0 or Mod <= x) x %= Mod;
    if (x < 0) x += Mod;
    v = x;
  }
  explicit Modint(long long x) {
    if (x < 0 or Mod <= x) x %= Mod;
    if (x < 0) x += Mod;
    v = x;
  }
  explicit Modint(unsigned x) {
    if (Mod <= x) x %= Mod;
    v = x;
  }
  explicit Modint(unsigned long long x) {
    if (Mod <= x) x %= Mod;
    v = x;
  }
  template <typename T>
  explicit Modint(T x) {
    if (x < 0 or Mod <= x) x %= Mod;
    v = x;
  }
  Modint() : v(0) {}
  long long get() const { return v; }
  Modint mpow(Modint &n) const { return mpow(n.v); }
  Modint mpow(long long n) const {
    long long i = 1, p = v;
    Modint ret(1);
    while (i <= n) {
      if (i & n) ret *= p;
      i = (i << 1);
      p = (p * p) % Mod;
    }
    return ret;
  }
  Modint operator-() const { return (v ? Modint(Mod - v) : Modint(0)); }
  explicit operator int() const { return v; }
  explicit operator long long() const { return v; }
  Modint &operator+=(const Modint &a) {
    v = (v + a.v);
    if (v >= Mod) v -= Mod;
    return *this;
  }
  Modint &operator-=(const Modint &a) {
    v = (v - a.v);
    if (v < 0) v += Mod;
    return *this;
  }
  Modint &operator*=(const Modint &a) {
    v = (v * a.v) % Mod;
    return *this;
  }
  Modint &operator/=(const Modint &a) {
    v = (v * a.mpow(Mod - 2).v) % Mod;
    return *this;
  }
  template <class T>
  Modint &operator+=(const T &a) {
    v = (v + Modint(a).v);
    if (v >= Mod) v -= Mod;
    return *this;
  }
  template <class T>
  Modint &operator-=(const T &a) {
    v = (v - Modint(a).v);
    if (v < 0) v += Mod;
    return *this;
  }
  template <class T>
  Modint &operator*=(const T &a) {
    v = (v * Modint(a).v) % Mod;
    return *this;
  }
  template <class T>
  Modint &operator/=(const T &a) {
    v = (v * Modint(a).mpow(Mod - 2).v) % Mod;
    return *this;
  }
  friend Modint operator+(const Modint &a, const Modint &b) {
    return Modint(a) += b;
  }
  friend Modint operator-(const Modint &a, const Modint &b) {
    return Modint(a) -= b;
  }
  friend Modint operator*(const Modint &a, const Modint &b) {
    return Modint(a) *= b;
  }
  friend Modint operator/(const Modint &a, const Modint &b) {
    return Modint(a) /= b;
  }
  template <class T, class U>
  friend Modint operator+(const T &a, const U &b) {
    return Modint(a) += Modint(b);
  }
  template <class T, class U>
  friend Modint operator-(const T &a, const U &b) {
    return Modint(a) -= Modint(b);
  }
  template <class T, class U>
  friend Modint operator*(const T &a, const U &b) {
    return Modint(a) *= Modint(b);
  }
  template <class T, class U>
  friend Modint operator/(const T &a, const U &b) {
    return Modint(a) /= Modint(b);
  }
};

template <long long M>
ostream &operator<<(ostream &os, const Modint<M> m) {
  return os << m.v;
}
class Solver {
 public:
  string s;
  int d, l;
  void solve() {
    cin >> s >> d;
    l = s.size();
    vector<int> k(l);
    for (int i = 0; i < l; ++i) {
      k[i] = s[i] - '0';
    }
    //reverse(k.begin(), k.end());
    vector<vector<vector<Modint<>>>> dp(l, vector<vector<Modint<>>>(10, vector<Modint<>>(d)));
    for (int i = 0; i < 10; ++i) {
      dp[0][i][i % d] += Modint<>(1);
    }
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int g = 0; g < d; ++g) {
          for (int h = 0; h < 10; ++h) {
            dp[i][j][g] += dp[i - 1][h][((g - j) % d + d) % d];
          }
        }
      }
    }
    int sum = 0;
    Modint<> ans(0);
    for (int i = 0; i < l; ++i) {
      for (int j = 0; j <= (i == l - 1 ? k[i] : k[i] - 1); ++j) {
        int tmp = ((-sum) % d + d) % d;
        ans += dp[l - 1 - i][j][tmp];
      }
      sum += k[i];
    }
    cout << ans - 1 << endl;
  }
};

}  // namespace Problem

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(12);

  Problem::Solver sol;
  sol.solve();
  return 0;
}
