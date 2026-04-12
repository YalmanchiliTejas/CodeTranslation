#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

long long mul_mod(long long a, long long b, const long long MOD) {
  return b ? (mul_mod(a * 2, b / 2, MOD) + (b & 1 ? a : 0)) % MOD : 0;
}

long long bpow_mod(long long a, long long b, const long long MOD) {
  return (b ? bpow_mod(a * a % MOD, b / 2, MOD) * (b & 1 ? a : 1) : 1) % MOD;
}

long long inv_mod(long long a, const long long MOD) {
  return bpow_mod(a, MOD - 2, MOD);
}
vector<long long> MODS = {998244353};
template <int kind = 0, int fast = 0>
class mint {
 public:
  long long v;

  mint() : v(0) {}
  // mint(long long);
  mint(long long v)
      : v(fast == 0 ? (v < 0 ? (v % MODS[kind] + MODS[kind]) % MODS[kind]
                             : (v >= MODS[kind] ? v % MODS[kind] : v))
                    : (v)) {}
  long long get_mod() { return MODS[kind]; }
  long long get_val() { return v; }
  void take_mod() { v %= MODS[kind]; }
};

template <int kind, int fast>
ostream& operator<<(ostream& os, const mint<kind, fast>& x) {
  return os << (x.v % MODS[kind] + MODS[kind]) % MODS[kind];
}

template <int kind, int fast, int fast2>
bool operator==(mint<kind, fast>& a, mint<kind, fast2> b) {
  return a.v == b.v;
}
template <int kind, int fast, int fast2>
mint<kind, fast>& operator+=(mint<kind, fast>& a, mint<kind, fast2> b) {
  return a = a.v + b.v;
}
template <int kind>
mint<kind>& operator-=(mint<kind>& a, mint<kind> b) {
  return a = a.v - b.v;
}
template <int kind>
mint<kind>& operator*=(mint<kind>& a, mint<kind> b) {
  return a = a.v * b.v;
}
template <int kind>
mint<kind>& operator/=(mint<kind>& a, mint<kind> b) {
  return a = a.v * inv_mod(b.v, a.get_mod());
}
template <int kind, int fast, int fast2>
mint<kind, fast> operator+(mint<kind, fast> a, mint<kind, fast2> b) {
  return a += b;
}
template <int kind>
mint<kind> operator-(mint<kind> a, mint<kind> b) {
  return a -= b;
}
template <int kind>
mint<kind> operator*(mint<kind> a, mint<kind> b) {
  return a *= b;
}
template <int kind>
mint<kind> operator/(mint<kind> a, mint<kind> b) {
  return a /= b;
}
template <int kind, int fast>
mint<kind, fast>& operator+=(mint<kind, fast>& a, long long b) {
  return a = a.v + b;
}
template <int kind>
mint<kind>& operator-=(mint<kind>& a, long long b) {
  return a = a.v - b;
}
template <int kind>
mint<kind>& operator*=(mint<kind>& a, long long b) {
  return a = a.v * b;
}
template <int kind>
mint<kind>& operator/=(mint<kind>& a, long long b) {
  return a = a.v * inv_mod(b, a.get_mod());
}
template <int kind, int fast>
mint<kind, fast> operator+(mint<kind, fast> a, long long b) {
  return a += b;
}
template <int kind>
mint<kind> operator-(mint<kind> a, long long b) {
  return a -= b;
}
template <int kind>
mint<kind> operator*(mint<kind> a, long long b) {
  return a *= b;
}
template <int kind>
mint<kind> operator/(mint<kind> a, long long b) {
  return a /= b;
}

int main() {
  MODS[0] = 1000000007;
  string K;
  int D;
  cin >> K >> D;
  MODS.push_back(D);

  int N = K.size();
  vector<vector<mint<>>> dp(N + 1, vector<mint<>>(D, 0));

  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < D; j++) {
      for (int k = 0; k < 10; k++) {
        mint<1> to = (j + k);
        dp[i][to.get_val()] += dp[i - 1][j];
      }
    }
  }

  mint<1> sum = 0;
  mint<> ans = -1;
  for (int i = 0; i < N; i++) {
    int digit = (K[i] - '0');
    for (int j = 0; j < digit; j++) {
      mint<1> ind = 0;
      ind -= sum + j;
      ans += dp[N - i - 1][ind.get_val()];
    }
    sum += digit;
  }
  if (sum.get_val() == 0) ans += 1;
  cout << ans << endl;

  return 0;
}