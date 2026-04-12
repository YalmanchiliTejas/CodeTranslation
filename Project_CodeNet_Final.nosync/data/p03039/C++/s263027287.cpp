#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
template <uint MOD>
struct ModInt {
  using M = ModInt;
  uint v;
  ModInt() : v(0) {}
  ModInt(ll _v) { norm(_v % MOD + MOD); }
  M& norm(uint _v) {
    v = (_v < MOD) ? _v : _v - MOD;
    return *this;
  }
  bool operator<(const M x) const { return this->v < x.v; }
  M operator+(const M x) const { return M().norm(v + x.v); }
  M operator-(const M x) const { return M().norm(v + MOD - x.v); }
  M operator*(const M x) const { return M().norm(ll(v) * x.v % MOD); }
  M operator/(const M x) const { return *this * x.inv(); }
  M& operator+=(const M x) { return *this = *this + x; }
  M& operator-=(const M x) { return *this = *this - x; }
  M& operator*=(const M x) { return *this = *this * x; }
  M& operator/=(const M x) { return *this = *this / x; }
  M& operator++() { return *this += 1; }
  friend istream& operator>>(istream& input, M& x) {
    input >> x.v, x.norm(x.v);
    return input;
  }
  friend ostream& operator<<(ostream& output, const M& x) {
    return output << x.v;
  }
  M pow(ll n) const {
    M x(v), res(1);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  M inv() const { return (*this).pow(MOD - 2); }

  static vector<M> fact, finv;
  static void build(int n) {
    fact.assign(n + 1, 1);
    finv.assign(n + 1, 1);
    for (int i = 1; i < n + 1; i++) fact[i] = fact[i - 1] * M(i);
    for (int i = 0; i < n + 1; i++) finv[i] = fact[i].inv();
  }
  static M comb(int n, int k) {
    if (n < k || k < 0) return M(0);
    return fact[n] * finv[n - k] * finv[k];
  }
};
template <uint MOD>
vector<ModInt<MOD>> ModInt<MOD>::fact = vector<ModInt<MOD>>();
template <uint MOD>
vector<ModInt<MOD>> ModInt<MOD>::finv = vector<ModInt<MOD>>();
using mint = ModInt<uint(1e9 + 7)>;

int main() {
  mint n, m, k;
  cin >> n >> m >> k;
  mint x = 0;
  for (mint i = 1; i < m; ++i) {
    x += i * (m - i) * n * n;
  }
  mint y = 0;
  for (mint i = 1; i < n; ++i) {
    y += i * (n - i) * m * m;
  }
  mint sum = x + y;
  mint::build(n.v * m.v);
  cout << sum * mint::comb(n.v * m.v - 2, k.v - 2) << endl;
}
