#include <bits/stdc++.h>

using namespace std;

template <long long Mod> struct ModInt { /* {{{ */
  long long v;
  constexpr ModInt(const long long x = 0) {
    v = x % Mod;
    if (v < 0) {
      v += Mod;
    }
  }
  constexpr ModInt operator+(const ModInt rhs) const { return ModInt(*this) += rhs; }
  constexpr ModInt operator-(const ModInt rhs) const { return ModInt(*this) -= rhs; }
  constexpr ModInt operator*(const ModInt rhs) const { return ModInt(*this) *= rhs; }
  constexpr ModInt operator/(const ModInt rhs) const { return ModInt(*this) /= rhs; }
  const ModInt &operator+=(const ModInt rhs) {
    v += rhs.v;
    if (v >= Mod) {
      v -= Mod;
    }
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt rhs) {
    if (v < rhs.v) {
      v += Mod;
    }
    v -= rhs.v;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt rhs) {
    v = v * rhs.v % Mod;
    return *this;
  }
  constexpr ModInt &operator/=(ModInt rhs) {
    long long exp = Mod - 2;
    while (exp) {
      if (exp & 1) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp >>= 1;
    }
    return *this;
  }
  friend ostream &operator<<(ostream &s, ModInt<Mod> m) {
    s << m.v;
    return s;
  }
  friend istream &operator>>(istream &s, ModInt<Mod> m) {
    s >> m.v;
    return s;
  }
}; /* }}} */

const int mod = 1e9 + 7;
using modint = ModInt<mod>;

modint fact[1000005];

int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  fact[0] = fact[1] = 1;
  for (int i = 2; i < 1000005; i++) {
    fact[i] = fact[i - 1] * i;
  }
  // i * (M-i) * N*N * (N*M-2)C(K-2)
  modint x = 0;
  for (int i = 1; i < M; i++) {
    x += i * (M - i);
  }
  x *= N * N;
  modint y = 0;
  for (int i = 1; i < N; i++) {
    y += i * (N - i);
  }
  y *= M * M;
  modint ans = (x + y) * fact[N * M - 2] / fact[K - 2] / fact[N * M - K];
  cout << ans << endl;
  return 0;
}
/* vim:set fdm=marker: */
