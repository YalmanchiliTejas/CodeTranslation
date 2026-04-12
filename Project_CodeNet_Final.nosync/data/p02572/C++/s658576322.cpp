#line 1 "c.cpp"
// -----------------------------------
// author   : MatsuTaku
// country  : Japan
// created  : 08/29/20 20:54:54
// -----------------------------------

#include <bits/stdc++.h>
#line 3 "/mnt/c/Users/tkmma/competitive_programming/CPBF/library/include/modular.hpp"

template <long long MOD>
class Modular {
 private:
  long long val_;

 public:
  constexpr Modular() : val_(0) {}
  constexpr Modular(long long v) : val_(v%MOD) {
    if (val_ < 0) val_ += MOD;
  }

  constexpr long long val() const { return val_; }
  constexpr Modular operator+(Modular x) const { return (val() + x.val())%MOD; }
  constexpr Modular operator+=(Modular x) { return *this = *this + x; }
  constexpr Modular operator++() { return *this += 1; }
  constexpr Modular operator++(int) { Modular c = *this; ++(*this); return c; }
  constexpr Modular operator-(Modular x) const { return (val() + MOD - x.val())%MOD; }
  constexpr Modular operator-=(Modular x) { return *this = *this - x; }
  constexpr Modular operator--() { return *this -= 1; }
  constexpr Modular operator--(int) { Modular c = *this; --(*this); return c; }
  constexpr Modular operator*(Modular x) const { return (val() * x.val())%MOD; }
  constexpr Modular operator*=(Modular x) { return *this = *this * x; }
  friend constexpr Modular pow(Modular x, long long p) {
    Modular t = 1;
    Modular u = x;
    while (p) {
      if (p & 1)
        t *= u;
      u *= u;
      p >>= 1;
    }
    return t;
  }
  constexpr Modular operator/(Modular x) const { return *this * pow(Modular{x}, MOD-2); }
  constexpr Modular operator/=(Modular x) { return *this = *this / x; }

  constexpr bool operator==(Modular x) const { return val() == x.val(); }
  constexpr bool operator!=(Modular x) const { return val() != x.val(); }
  constexpr bool operator<(Modular x) const { return val() < x.val(); };
  constexpr bool operator<=(Modular x) const { return val() <= x.val(); };
  constexpr bool operator>(Modular x) const { return val() > x.val(); };
  constexpr bool operator>=(Modular x) const { return val() >= x.val(); };

  friend std::ostream& operator<<(std::ostream& os, const Modular& x) {
    return os << x.val();
  }
  friend std::istream& operator>>(std::istream& is, Modular& x) {
    return is >> x.val_;
  }

};

#line 9 "c.cpp"

using namespace std;
using ll = long long;
constexpr int MOD = 1e9+7;
using mint = Modular<MOD>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n; cin>>n;
  vector<mint> A(n); for (auto& a:A) cin>>a;
  mint ans = 0;
  mint cum = A[n-1];
  for (int i = n-2; i >= 0; i--) {
    ans += A[i] * cum;
    cum += A[i];
  }
  cout << ans << endl;

  return 0;
}
