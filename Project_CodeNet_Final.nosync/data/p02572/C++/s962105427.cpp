#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x) for (auto&& v : (x))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))

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
long long modint::M = 1e9 + 7;

modint a[200100];
int main() {
  ll n;
  cin >> n;
  rep(i, n) cin >> a[i];
  modint sum(0), sum2(0);
  rep(i, n) sum += a[i];
  rep(i, n) sum2 += a[i].pow(2);
  cout << (sum.pow(2) - sum2) / 2 << endl;
}
