// -----------------------------------
// Author     : MatsuTaku
// Affiliation: Tokushima University
// Country    : Japan
// Date       : 03/22/2020
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T, T MOD>
class modint {
 private:
  T val_;

 public:
  constexpr modint() : val_(0) {}
  constexpr modint(T v) : val_(v%MOD) {}
  constexpr modint& operator=(T v) { val_ = v%MOD; return *this; }

  constexpr T val() const { return val_; }
  constexpr modint operator+(modint x) const { return (val() + x.val())%MOD; }
  constexpr modint operator+=(modint x) { return *this = *this + x; }
  constexpr modint operator++() { return *this += 1; }
  constexpr modint operator++(int) { modint c = *this; ++(*this); return c; }
  constexpr modint operator-(modint x) const { return (val() + MOD - x.val())%MOD; }
  constexpr modint operator-=(modint x) { return *this = *this - x; }
  constexpr modint operator--() { return *this -= 1; }
  constexpr modint operator--(int) { modint c = *this; --(*this); return c; }
  constexpr modint operator*(modint x) const { return (val() * x.val())%MOD; }
  constexpr modint operator*=(modint x) { return *this = *this * x; }
  friend constexpr modint pow(modint x, T p) {
    modint t = 1;
    modint u = x;
    while (p) {
      if (p & 1)
        t *= u;
      u *= u;
      p >>= 1;
    }
    return t;
  }
  constexpr modint operator/(modint x) const { return *this * pow(modint{x}, MOD-2); }
  constexpr modint operator/=(modint x) { return *this = *this / x; }

  constexpr bool operator==(modint x) const { return val() == x.val(); }
  constexpr bool operator!=(modint x) const { return val() != x.val(); }
  constexpr bool operator<(modint x) const { return val() < x.val(); };
  constexpr bool operator<=(modint x) const { return val() <= x.val(); };
  constexpr bool operator>(modint x) const { return val() > x.val(); };
  constexpr bool operator>=(modint x) const { return val() >= x.val(); };

  friend std::ostream& operator<<(std::ostream& os, modint x) {
    return os << x.val();
  }
  friend std::istream& operator>>(std::istream& is, modint& x) {
    return is >> x.val_;
  }

};

constexpr ll MOD = 998244353;
using mint = modint<unsigned long long, MOD>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N,S; cin>>N>>S;
  vector<ll> A(N); for(auto& a : A) cin>>a;

  mint ans = 0;
  vector<mint> dp(S+1);
  for (int i = 0; i < N; i++) {
    dp[0] = i+1;
    for (int s = S-A[i]; s >= 0; s--) {
      dp[s+A[i]] += dp[s];
    }
    ans += dp[S];
  }
  cout << ans << endl;

  return 0;
}
