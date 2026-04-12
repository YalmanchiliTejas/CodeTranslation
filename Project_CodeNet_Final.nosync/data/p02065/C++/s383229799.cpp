#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct Mint {
  using M = Mint;
  static unsigned P;
  unsigned v;
  Mint() : v(0) {}
  Mint(auto x) : v(x >= 0 ? x % P : (P - -x % P) % P) {}
  constexpr Mint(unsigned v, int) : v(v) {}
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool)*this; }
  M operator*(M r) const { return M(*this) *= r; }
  M operator/(M r) const { return M(*this) /= r; }
  M operator+(M r) const { return M(*this) += r; }
  M operator-(M r) const { return M(*this) -= r; }
  bool operator==(M r) const { return v == r.v; }
  bool operator!=(M r) const { return !(*this == r); }
  M& operator*=(M r) { v = (uint64_t)v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
  M inv() const {
    int a = v, b = P, x = 1, u = 0;
    while (b) {
      int q = a / b;
      swap(a -= q * b, b);
      swap(x -= q * u, u);
    }
    assert(a == 1);
    return x;
  }
  M pow(auto n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  friend M operator*(auto l, M r) { return M(l) *= r; }
  friend M operator/(auto l, M r) { return M(l) /= r; }
  friend M operator+(auto l, M r) { return M(l) += r; }
  friend M operator-(auto l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend istream& operator>>(istream& is, M& r) { lint x; is >> x; r = x; return is; }
  friend bool operator==(auto l, M r) { return M(l) == r; }
  friend bool operator!=(auto l, M r) { return !(l == r); }
};
unsigned Mint::P;

map< V<>, Mint> dp[101][101];

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k >> Mint::P;
  dp[1][0][{0, 0, 0}] = 1;
  for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) {
    for (const auto& e : dp[i][j]) {
      auto v = e.first;
      if (v.size() >= 3 and i + j - min(v[0], v[2]) > k) continue;
      if (i + 1 <= n and i + j - v.back() <= k) {
        auto nv = v;
        nv.push_back(i + j);
        dp[i + 1][j][nv] += e.second;
      }
      if (j + 1 <= i and i + j - min(v[0], v[2]) <= k) {
        auto nv = v;
        nv.erase(begin(nv));
        nv[0] = i + j;
        dp[i][j + 1][nv] += e.second;
      }
    }
  }
  Mint res;
  for (const auto& e : dp[n][n]) res += e.second;
  cout << res << '\n';
}
