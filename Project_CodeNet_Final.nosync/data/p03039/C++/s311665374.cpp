#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// mint
template<int64_t Prime>
struct mod_int {
  int64_t v_;
  mod_int(int64_t x=0) : v_(x) { normalize(); }
  void normalize() { ((v_ %= Prime) += Prime) %= Prime; }
  mod_int operator+=(mod_int const& r){ (v_ += r.v_) %= Prime; return *this; }
  mod_int operator-=(mod_int const& r){ (v_ += Prime - r.v_) %= Prime; return *this; }
  mod_int operator*=(mod_int const& r){ (v_ *= r.v_) %= Prime; return *this; }
  mod_int operator+(mod_int const& r) const { mod_int res(*this); return res += r; }
  mod_int operator-(mod_int const& r) const { mod_int res(*this); return res -= r; }
  mod_int operator*(mod_int const& r) const { mod_int res(*this); return res *= r; }
  mod_int pow(int x) const {
    int64_t res = 1, v = v_;
    while(x > 0) {
      if(x&1) (res *= v) %= Prime;
      x/=2; (v *= v) %= Prime;
    }
    return mod_int(res);
  }
  mod_int inv() const { return pow(Prime-2); }
};

int64_t const MOD = 1e9+7;
typedef mod_int<MOD> mint;

// fact
template<typename INT>
struct factorial {
  std::vector<INT> fact, ifact;
  void init(int64_t N) {
    fact.resize(N+1); ifact.resize(N+1);
    fact[0] = fact[1] = INT(1);
    for(int i = 2; i <= N; ++i) fact[i] = fact[i-1]*i;
    ifact[N] = fact[N].inv();
    for(int i = N-1; i >= 0; --i) ifact[i] = ifact[i+1]*(i+1);
  }
  INT comb(int64_t n, int64_t k) { // nCk
    if(k > n || k < 0) return INT(0);
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int64_t N, M, K; std::cin >> N >> M >> K;
  factorial<mint> F;
  F.init(std::max(N*M, std::max(N, M)+1));
  mint ans = mint(M*M)*F.comb(N+1,3) + mint(N*N)*F.comb(M+1,3);
  ans *= F.comb(N*M-2, K-2);
  fin(ans.v_);
  return 0;
}
