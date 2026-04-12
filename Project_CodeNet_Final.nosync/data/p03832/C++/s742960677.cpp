#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;
vector<vector<int>> dp;
template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

Modular<> fact[1005], inv[1005];
Modular<> ncr(int nn, int r) {
  return fact[nn] * inv[nn - r] * inv[r];
}

Modular<> groups(int nn, int g) {
  return fact[nn] * mexp(inv[g], nn/g) * inv[nn/g];
}

int solve(int rem, int cur) {
  if (cur > b) return (rem == 0);
  if (dp[rem][cur] != -1) return dp[rem][cur];
  Modular<> ret = 0;

  ret += solve(rem, cur + 1);
  for (int i = cur * c; i <= cur * d; i += cur) {
    if (i > rem)  break;
    ret += ncr(rem, i) * groups(i, cur) * solve(rem - i, cur + 1);
  }
  return (dp[rem][cur] = ret.value);
}

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  fact[0] = inv[0] = 1;
  for (int i = 1; i < 1005; ++i) {
    fact[i] = i * fact[i-1];
    inv[i] = 1 / fact[i];
  }

  cin >> n >> a >> b >> c >> d;
  dp.resize(n + 1, vector<int> (n + 1, -1));
  cout << solve(n, a) << '\n';
}
