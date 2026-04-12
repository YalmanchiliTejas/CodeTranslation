#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  template<class Int> ModInt(Int x) : v(x >= 0 ? x % P : -x % P ? P - -x % P : 0) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M rhs) const { return M(*this) *= rhs; }
  M operator/(M rhs) const { return M(*this) /= rhs; }
  M operator+(M rhs) const { return M(*this) += rhs; }
  M operator-(M rhs) const { return M(*this) -= rhs; }
  bool operator==(M rhs) const { return v == rhs.v; }
  bool operator!=(M rhs) const { return !(*this == rhs); }
  M& operator*=(M rhs) { v = (unsigned long long) v * rhs.v % P; return *this; }
  M& operator/=(M rhs) { return *this *= rhs.inv(); }
  M& operator+=(M rhs) { v = rhs.v < P - v ? v + rhs.v : v - (P - rhs.v); return *this; }
  M& operator-=(M rhs) { v = rhs.v <= v ? v - rhs.v : v + (P - rhs.v); return *this; }
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
  template<class Int> M pow(Int n) const {
    n = n >= 0 ? n % (P - 1) : P - 1 - -n % (P - 1);
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  template<class Int> friend M operator*(Int lhs, M rhs) { return M(lhs) *= rhs; }
  template<class Int> friend M operator/(Int lhs, M rhs) { return M(lhs) /= rhs; }
  template<class Int> friend M operator+(Int lhs, M rhs) { return M(lhs) += rhs; }
  template<class Int> friend M operator-(Int lhs, M rhs) { return M(lhs) -= rhs; }
  friend ostream& operator<<(ostream& os, M rhs) { return os << rhs.v; }
  friend istream& operator>>(istream& is, M& rhs) { lint x; is >> x; rhs = x; return is; }
  template<class Int> friend bool operator==(Int lhs, M rhs) { return M(lhs) == rhs; }
  template<class Int> friend bool operator!=(Int lhs, M rhs) { return !(lhs == rhs); }
};
using Mint = ModInt<(unsigned) 1e9 + 7>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> h(n + 1, 1), hs;
  for (int i = 0; i <= n; ++i) {
    if (i) cin >> h[i];
    hs.push_back(h[i]);
    hs.push_back(h[i] + 1);
  }
  sort(begin(hs), end(hs));
  hs.erase(unique(begin(hs), end(hs)), end(hs));
  auto h2j = [&](int h) -> int {
    return lower_bound(begin(hs), end(hs), h) - begin(hs);
  };
  int m = hs.size();
  V<Mint> dp(m - 1);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    V<Mint> ndp(m - 1);
    if (h[i] <= h[i + 1]) {
      for (int j = 0; hs[j] < h[i]; ++j) {
        ndp[j] += Mint(2).pow(h[i + 1] - h[i]) * dp[j];
      }
      for (int j = h2j(h[i]); hs[j] < h[i + 1]; ++j) {
        ndp[j] += (Mint(2).pow(h[i + 1] - hs[j] + 1) - Mint(2).pow(h[i + 1] - hs[j + 1] + 1)) * dp[h2j(h[i])];
      }
      ndp[h2j(h[i + 1])] += 2 * dp[h2j(h[i])];
    } else {
      for (int j = 0; hs[j] < h[i + 1]; ++j) {
        ndp[j] += dp[j];
      }
      for (int j = h2j(h[i + 1]); hs[j] <= h[i]; ++j) {
        ndp[h2j(h[i + 1])] += 2 * dp[j];
      }
    }
    swap(dp, ndp);
  }
  cout << accumulate(begin(dp), end(dp), Mint(0)) << '\n';
}