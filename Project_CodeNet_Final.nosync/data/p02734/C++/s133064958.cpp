#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<long long mod>
class modint{
private:
  long long a;
public:
  constexpr modint(const long long x = 0) noexcept : a(x%mod) {}
  constexpr long long& value() noexcept { return a; }
  constexpr const long long& value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if(a >= mod) a -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if(a < rhs.a) a += mod;
    a -= rhs.a;
    return *this;
  }
  constexpr modint& operator*=(const modint rhs) noexcept {
    a = a*rhs.a%mod;
    return *this;
  }
  constexpr modint& operator/=(modint rhs) noexcept {
    long long k = mod-2;
    while(k > 0){
      if(k&1){
        *this *= rhs;
      }
      rhs *= rhs;
      k /= 2;
    }
    return *this;
  }
  friend ostream& operator<<(ostream &os, const modint &X){
    return os << X.a;
  }
  friend istream& operator>>(istream &is, modint &X){
    is >> X.a;
    X.a %= mod;
    if(X.a < 0) X.a += mod;
    return is;
  }
};


int main(){
  using mint = modint<998244353>;
  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  vector<mint> dp(S+1);
  mint ans = 0;
  for(int i = 0; i < N; ++i){
    if(A[i] <= S){
      for(int j = S-A[i]; j >= 0; --j){
        dp[j+A[i]] += dp[j];
      }
      dp[A[i]] += i+1;
    }
    ans += dp[S];
    // cerr << i << " " << dp[S] <<endl;
  }
  cout << ans << endl;
}
