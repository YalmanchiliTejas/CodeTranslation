#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL 
#include "/home/gokul/Codes/lib/prettyprint.hpp"
#else
#define debug(...) 2
#endif

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

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  Modular<> dp[n + 1][n + 1], fact[n + 1], inv[n + 1];
  memset(dp, 0, sizeof dp);
  inv[0] = fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = i * fact[i - 1];
    inv[i] = 1 / fact[i];
  }

  auto ncr = [&](int nn, int rr) {
    return fact[nn] * inv[nn - rr] * inv[rr];
  };

  auto groups = [&](int nn, int g) {
    return fact[nn] * mexp(inv[g], nn/g) * inv[nn/g];
  }; 

  dp[0][a-1] = 1;
  for (int i = a; i <= b; ++i) {

    for (int used = 0; used <= n; ++used) {
      dp[used][i] += dp[used][i-1];
    } 

    for (int j = i * c; j <= i * d; j += i) {
      for (int used = n; used >= 0; --used) {
        if (j + used <= n) {
          dp[j + used][i] += dp[used][i - 1] * ncr(n - used, j) * groups(j, i);  
        }
      }         
    }
    
  } 

  cout << dp[n][b] << '\n';
}