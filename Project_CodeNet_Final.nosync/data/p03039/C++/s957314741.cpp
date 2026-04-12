#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl 
#define debug(x) (cout << #x << ": " << x << endl)
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

#include <boost/operators.hpp>

class modint : private boost::operators<modint>, private boost::equivalent<modint> {
  modint(const long long x, const bool y)
      : x(x) {}

 public:
  static long long M;
  long long x;
  modint(const long long x = 0)
      : x((x % M + M) % M) {}
  modint operator-() const { return modint(x ? M - x : 0, true); }
  modint& operator+=(const modint& b) { return ((x += b.x) >= M ? x -= M : 0), *this; }
  modint& operator++() { return (++x >= M ? x -= M : 0), *this; }
  modint& operator-=(const modint& b) { return ((x -= b.x) < 0 ? x += M : 0), *this; }
  modint& operator--() { return (--x < 0 ? x += M : 0), *this; }
  modint& operator*=(const modint& b) { return x = x * b.x % M, *this; }
  modint& operator/=(const modint& b) { return *this *= b.pow(-1); }
  modint pow(long long b) const {
    long long r = 1, a = x;
    b = (b % (M - 1) + (M - 1)) % (M - 1);
    while (b) {
      if (b & 1) r = r * a % M;
      b = b >> 1;
      a = a * a % M;
    }
    return modint(r, true);
  }
  friend bool operator<(const modint& a, const modint& b) { return a.x < b.x; }
  friend std::istream& operator>>(std::istream& s, modint& a) { return s >> a.x, a = a.x, s; }
  friend std::ostream& operator<<(std::ostream& s, const modint& a) { return s << a.x; }
};
long long modint::M = 1000000007;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<modint> fact(n * m + 1);
  fact[0] = 1;
  rep(i, fact.size() - 1) fact[i + 1] = (i + 1) * fact[i];
  auto nmCk_2 = fact[n * m - 2] / fact[k - 2] / fact[n * m - 2 - (k - 2)];
  auto h = [](ll x) { return x * (x + 1) / 2; };
  auto g = [&h](ll x) {
    modint re;
    rep(i, x) re += h(i) + h(x - i - 1);
    return re;
  };
  // debug(nmCk_2);
  // debug(g(n));
  // debug(g(m));
  cout << nmCk_2 / 2 * (g(n) * m * m + g(m) * n * n) << endl;
}
