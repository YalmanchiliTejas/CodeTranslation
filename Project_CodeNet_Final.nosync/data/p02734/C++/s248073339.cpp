#line 1 "../../../lib/math/modint.hpp"
#include <cstdint>
#include <iostream>
#ifndef MOD_INT
#define MOD_INT

template <std::uint_fast64_t MOD> class ModInt {
  using u64 = std::uint_fast64_t;

public:
  ModInt(const u64 val = 0) { value = val % MOD; }

  bool operator==(const ModInt &rhs) const { return value == rhs.value; }
  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }
  bool operator<(const ModInt &rhs) const { return value < rhs.value; }
  bool operator>(const ModInt &rhs) const { return value > rhs.value; }
  bool operator<=(const ModInt &rhs) const { return !(*this > rhs); }
  bool operator>=(const ModInt &rhs) const { return !(*this < rhs); }

  ModInt operator+(const ModInt rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt rhs) const { return ModInt(*this) /= rhs; }

  ModInt &operator+=(const ModInt rhs) {
    value += rhs.value;
    if (value >= MOD) {
      value -= MOD;
    }
    return *this;
  }

  ModInt &operator-=(const ModInt rhs) {
    if (value < rhs.value) {
      value += MOD;
    }
    value -= rhs.value;
    return *this;
  }

  ModInt &operator*=(const ModInt rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }

  ModInt &operator/=(ModInt rhs) {
    *this *= rhs.inv();
    return *this;
  }

  ModInt &operator++(int n) {
    value++;
    if (value >= MOD) {
      value -= MOD;
    }
    return *this;
  }

  ModInt &operator--(int n) {
    if (value == 0) {
      value += MOD;
    }
    value--;
    return *this;
  }

  ModInt inv() { return ModInt::pow(*this, MOD - 2); }

  static ModInt pow(ModInt base, long long int n) {
    ModInt res = ModInt(1);
    while (n) {
      if (n & 1) {
        res *= base;
      }
      base *= base;
      n /= 2;
    }
    return res;
  }

  static ModInt comb(ModInt n, ModInt r) { return comb(n.value, r.value); }

  static ModInt comb(int n, int r) {
    if (n < r)
      return ModInt(0);
    ModInt res = ModInt(1);
    for (int i = 0; i < r; i++) {
      res *= ModInt(n - i);
    }

    ModInt inv = ModInt(1);
    for (int i = 0; i < r; i++) {
      inv *= ModInt(r - i);
    }
    return res / inv;
  }

  u64 getValue() const { return value; }

private:
  u64 value;

  friend std::ostream &operator<<(std::ostream &out, const ModInt<MOD> &m) {
    out << m.value;
    return out;
  }

  friend std::istream &operator>>(std::istream &in, ModInt &m) {
    uint_fast64_t i;
    in >> i;
    m = ModInt(i);
    return in;
  }
};

#endif
#line 2 "abc159_f.cpp"
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
using P = std::pair<int, int>;
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;
using mint = ModInt<998244353>;

int main() {
  int n, s;
  cin >> n >> s;
  vi a(n);
  mint ans(0);
  REP(i, n) { cin >> a[i]; }

  vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(s + 1, vector<mint>(3, mint(0))));
  dp[0][0][0] = mint(1);
  if (a[0] <= s) {
    dp[0][a[0]][1] = mint(1);
    dp[0][a[0]][2] = mint(1);
  }

  FOR(i, 1, n) {
    REP(j, s + 1) {
      dp[i][j][0] += dp[i - 1][j][0];
      dp[i][j][1] += dp[i - 1][j][1];
      dp[i][j][2] += dp[i - 1][j][2];
      if (j - a[i] >= 0) {
        dp[i][j][1] += dp[i - 1][j - a[i]][0] * mint(i + 1) + dp[i - 1][j - a[i]][1];
        dp[i][j][2] += dp[i - 1][j - a[i]][1] * mint(n - i) + dp[i - 1][j - a[i]][0] * mint(i + 1) * mint(n - i);
      }
    }
  }
  cout << dp[n - 1][s][2] << endl;
}
