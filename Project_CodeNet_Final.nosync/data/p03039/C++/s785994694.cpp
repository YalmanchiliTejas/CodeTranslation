#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; ++i)
#define all(a) (a).begin(), (a).end()
template <int MOD>
class ModInt {
  long long x;

 public:
  ModInt(long long v = 0) : x(v % MOD) {
    if (x < 0) x += MOD;
  }

  ModInt& operator+=(const ModInt& r) {
    x += r.x;
    if (x >= MOD) x -= MOD;
    return *this;
  }

  ModInt& operator-=(const ModInt& r) {
    x -= r.x;
    if (x < 0) x += MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt& r) {
    x = (x * r.x) % MOD;
    return *this;
  }
  ModInt& operator/=(const ModInt& r) {
    *this *= r.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt& r) const { return ModInt(*this) += r; }
  ModInt operator-(const ModInt& r) const { return ModInt(*this) -= r; }
  ModInt operator*(const ModInt& r) const { return ModInt(*this) *= r; }
  ModInt operator/(const ModInt& r) const { return ModInt(*this) /= r; }
  bool operator==(const ModInt& r) const { return x == r.x; }
  bool operator!=(const ModInt& r) const { return x != r.x; }

  ModInt inverse() const {
    long long a = x, b = MOD, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt<MOD> pow(long long n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream& operator<<(ostream& os, const ModInt& x) { return os << x.x; }

  friend istream& operator>>(istream& is, ModInt& x) { return is >> x.x; }

  int getMod() { return MOD; }

  long long val() { return x; }
};

using mint = ModInt<1000000007>;

int N, M, K;

int main() {
  cin >> N >> M >> K;

  vector<mint> fact(N * M - 1), ifact(N * M - 1);
  fact[0] = 1;
  rep(i, N * M - 2) fact[i + 1] = fact[i] * (i + 1);
  rep(i, N * M - 1) ifact[i] = fact[i].inverse();

  auto comb = [&](int n, int k) { return fact[n] * ifact[k] * ifact[n - k]; };

  mint ans = 0;
  rep(i, M) ans += comb(N * M - 2, K - 2) * i * (M - i) * N * N;
  rep(i, N) ans += comb(N * M - 2, K - 2) * i * (N - i) * M * M;

  cout << ans << endl;
  return 0;
}
