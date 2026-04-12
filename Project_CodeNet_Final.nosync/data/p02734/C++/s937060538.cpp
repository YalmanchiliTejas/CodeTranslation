#include <bits/stdc++.h>

using namespace std;

template <long long Mod> struct ModInt {
  long long v;
  constexpr ModInt(const long long x = 0) {
    v = x % Mod;
    if (v < 0) {
      v += Mod;
    }
  }
  constexpr ModInt operator+(const ModInt rhs) const {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt rhs) const {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt rhs) const {
    return ModInt(*this) /= rhs;
  }
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
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
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
};

const int mod = 998244353;
using modint = ModInt<mod>;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for (auto &a : A) {
    cin >> a;
  }
  vector<vector<modint>> dp(N + 1, vector<modint>(S + 1));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < S + 1; j++) {
      if (j == 0) {
        dp[i][j] += 1;
      }
      dp[i + 1][j] += dp[i][j];
      if (j + A[i] < S + 1) {
        dp[i + 1][j + A[i]] += dp[i][j];
      }
    }
  }
  modint ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += dp[i][S];
  }
  cout << ans.v << endl;

  return 0;
}
