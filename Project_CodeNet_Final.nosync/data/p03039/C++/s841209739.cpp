#include <iostream>
#include <vector>
#include <cassert>
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


template<typename T>
struct Combination {
private:
  int sz;
  vector<T> F, F_;
public:
  Combination(int sz) : sz(sz), F(sz+1), F_(sz+1) {
    F[0] = 1;
    for(int i = 0; i < sz; ++i) F[i+1] = F[i]*(i+1);
    F_.back() = (T)1/F.back();
    for(int i = sz-1; i >= 0; --i) F_[i] = F_[i+1]*(i+1);
  }
  T C(int n, int k){
    assert(n <= sz);
    if(n < 0 or k > n) return (T)0;
    return F[n]*F_[k]*F_[n-k];
  }
};

int main(){
  using mint = modint<(int)1e9+7>;
  long long N, M, K;
  cin >> N >> M >> K;
  vector<vector<mint>> D(N,vector<mint>(M,0));
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      D[i][j] += i+j;
    }
  }
  for(int i = 0; i < N; ++i){
    for(int j = 1; j < M; ++j){
      D[i][j] += D[i][j-1];
    }
  }
  for(int i = 1; i < N; ++i){
    for(int j = 0; j < M; ++j){
      D[i][j] += D[i-1][j];
    }
  }
  Combination<mint> comb(N*M+1);
  mint ans = 0;
  mint t = comb.C(N*M-2,K-2);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      ans += t*D[i][j];
      ans += t*D[N-1-i][j];
      ans += t*D[i][M-1-j];
      ans += t*D[N-1-i][M-1-j];
      ans -= t*D[0][j];
      ans -= t*D[0][M-1-j];
      ans -= t*D[i][0];
      ans -= t*D[N-1-i][0];
    }
  }
  ans /= 2;
  cout << ans << endl;
}
