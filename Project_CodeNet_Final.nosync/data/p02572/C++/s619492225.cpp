#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

template<int64_t MOD> struct Mint {
  int64_t v;
  Mint() { v = 0; }
  Mint(int64_t x) { v = x % MOD; if(v < 0) v += MOD; }

  Mint operator-() { return Mint(-v); };
  Mint operator+(Mint x) { return Mint(v + x.v); };
  Mint operator-(Mint x) { return Mint(v - x.v); };
  Mint operator*(Mint x) { return Mint(v * x.v); };
  Mint operator/(Mint x) { return Mint(v * pow(x.v, MOD-2).v); };

  Mint& operator+=(Mint x) { return *this = (*this + x); };
  Mint& operator-=(Mint x) { return *this = (*this - x); };
  Mint& operator*=(Mint x) { return *this = (*this * x); };
  Mint& operator/=(Mint x) { return *this = (*this / x); };

  static Mint pow(Mint base, int64_t exp) {
    if(exp == 0) return Mint(1);
    return pow(base*base, exp/2) * (exp&1 ? base : Mint(1));
  }

  friend ostream& operator<<(ostream& os, Mint x) { return os << x.v; }
};
using mint = Mint<1000000007>;

const int SIZE = 11234567;
mint fact(int n) {
  static vector<mint> factorial = []() {
    vector<mint> _f(SIZE, 1);
    for(int i=1; i<SIZE; i++) _f[i] = _f[i-1] * i;
    return _f;
  }();
  return factorial[n];
}
mint perm(int n, int k) { return n<k ? 0 : fact(n) / fact(n-k); }
mint comb(int n, int k) { return n<k ? 0 : perm(n, k) / fact(k); }

int main() {
  lint N;
  cin >> N;
  vector<lint> A(N), S(N);
  for(auto& elem : A) cin >> elem;
  partial_sum(A.begin(), A.end(), S.begin());
  S.insert(S.begin(), 0);

  mint ans = 0;
  for(lint i=0; i<N; i++) {
    ans += mint(A[i]) * mint(S[N] - S[i+1]);
  }
  cout << ans << endl;
}