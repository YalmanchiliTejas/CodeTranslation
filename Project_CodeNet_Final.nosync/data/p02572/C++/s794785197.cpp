#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
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

  friend Modular inverse(Modular b, long long m = MOD) {
    long long u = 0, v = 1, a = b.value;
    while (a != 0) {
      long long t = m / a;
      m -= t * a; swap(a, m);
      u -= t * v; swap(u, v);
    }
    return Modular(u);
  }

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
using mint = Modular<M>;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  
  int n; 
  cin >> n;
  mint sum = 0;
  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  
  mint ans = 0;   
  for (int i = 0; i < n; ++i) {
    ans += (sum-a[i])*a[i];
  }
  
  ans /= 2;
  cout << ans << '\n';
}
