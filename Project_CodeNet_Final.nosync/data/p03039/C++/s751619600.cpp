#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
using ll = long long;

template <int M, bool IsPrime = false> class Modulo {
  int n;
  static typename std::enable_if<IsPrime, ll>::type inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
  }

public:
  Modulo() : n(0) { ; }
  Modulo(int m) : n(m) {
    if (n >= M)
      n %= M;
    else if (n < 0)
      n = (n % M + M) % M;
  }
  Modulo(ll m) {
    if (m >= M)
      m %= M;
    else if (m < 0)
      m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo &operator+=(const Modulo &a) {
    n += a.n;
    if (n >= M) n -= M;
    return *this;
  }
  Modulo &operator-=(const Modulo &a) {
    n -= a.n;
    if (n < 0) n += M;
    return *this;
  }
  Modulo &operator*=(const Modulo &a) {
    n = (ll(n) * a.n) % M;
    return *this;
  }
  Modulo operator+(const Modulo &a) const {
    Modulo res = *this;
    return res += a;
  }
  Modulo operator-(const Modulo &a) const {
    Modulo res = *this;
    return res -= a;
  }
  Modulo operator-() const { return Modulo(0) - *this; }
  Modulo operator*(const Modulo &a) const {
    Modulo res = *this;
    return res *= a;
  }

  Modulo operator^(ll m) const {
    if (m == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (m / 2);
    return m % 2 ? res * a : res;
  }
  typename std::enable_if<IsPrime, Modulo>::type
  operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
  typename std::enable_if<IsPrime, Modulo>::type operator/=(const Modulo &a) {
    return *this *= inv(ll(a), M);
  }

  friend bool is_zero(const Modulo &x) { return int(x) == 0; }
  friend int abs(const Modulo &x) { return int(x); }

  static Modulo fact(int n, bool sw = true) {
    static std::vector<Modulo> v1 = { 1 }, v2 = { 1 };
    if (n >= (int)v1.size()) {
      const int from = v1.size(), to = n + 1024;
      v1.reserve(to);
      v2.reserve(to);
      for (int i = from; i < to; ++i) {
        v1.push_back(v1.back() * Modulo<M, true>(i));
        v2.push_back(v2.back() / Modulo<M, true>(i));
      }
    }
    return sw ? v1[n] : v2[n];
  }
  static Modulo comb(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    return Modulo::fact(a, true) * Modulo::fact(b, false) *
           Modulo::fact(a - b, false);
  }
};
using Mod = Modulo<1000000007, true>;

int main(void)
{
  ll n,m,k;
  cin >> n >> m >> k;
  Mod answer=0;
  REP(i,n) {
    Mod tmp = (i*(i+1)/2 + (n-i)*(n-i-1)/2);
    tmp *= m;
    tmp *= m;
    answer += tmp;
  }
  REP(i,m) {
    Mod tmp = (i*(i+1)/2 + (m-i)*(m-i-1)/2);
    tmp *= n;
    tmp *= n;
    answer += tmp;
  }
  answer /= 2;
  answer *= Mod::comb(n*m-2,k-2);
  cout << (ll)answer << endl;
  return 0;
}
