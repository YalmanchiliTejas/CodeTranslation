/*
 * atcoder/abc127/e.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> ostream & operator << (ostream & out, vector<T> const & v) {
  for (auto &&a: v) out << a << " "; out << endl; return out;
}
template <class T> void dump(T &a) { cout << a << endl; }
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }
#define MOD 1000000007
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%MOD+MOD)%MOD){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%MOD+MOD)%MOD; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=MOD) x-=MOD; return *this;}
  mint& operator-=(const mint& a){ if((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=MOD; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
ostream & operator << (ostream & out, mint const & v) {
  out << v.x;
  return out;
}
template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[MOD%i] * (MOD/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};

ll H, W, K, S;
BiCoef<mint> bc;
void solve() {
  cin >> H >> W >> K;
  S = H*W;
  bc.init(S);

  mint total = 0;
  for (int d=1; d<H; d++) {
    total += d * (H-d) * W * W;
  }
  for (int d=1; d<W; d++) {
    total += d * (W-d) * H * H;
  }

  total *= bc.com(S-2, K-2);
  cout << total << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
