#include <iostream>
#include <vector>
using namespace std;

constexpr int mod = 1000000007;
class mint {
 public:
  long long x;
  constexpr mint(long long x = 0) : x((x % mod + mod) % mod) {}
  constexpr mint operator-() const { return mint(-x); }
  constexpr mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr mint& operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr mint& operator*=(const mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }
  constexpr mint operator+(const mint& a) const {
    mint res(*this);
    return res += a;
  }
  constexpr mint operator-(const mint& a) const {
    mint res(*this);
    return res -= a;
  }
  constexpr mint operator*(const mint& a) const {
    mint res(*this);
    return res *= a;
  }
  constexpr mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  constexpr mint inv() const { return pow(mod - 2); }
  constexpr mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
  constexpr mint operator/(const mint& a) const {
    mint res(*this);
    return res /= a;
  }
};
ostream& operator<<(ostream& os, const mint& m) {
  os << m.x;
  return os;
}

int main() {
  int n;
  cin >> n;
  vector<mint> a(n);
  for (int i = 0; i < n; ++i) {
    long long inp;
    cin >> inp;
    a[i] = inp;
  }
  mint msum = 0;
  mint mans = 0;
  for (int i = 0; i < n-1; ++i) {
    msum = msum + a[i];
    mans +=  msum * a[i+1];
  }
  cout << mans << endl;
}

