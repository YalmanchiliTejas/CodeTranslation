#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

struct mint {
  int val;
  constexpr mint(int v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr int getMOD() { return MOD; }
  constexpr mint operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  constexpr mint operator + (const mint& r) const noexcept { return mint(*this) += r; }
  constexpr mint operator - (const mint& r) const noexcept { return mint(*this) -= r; }
  constexpr mint operator * (const mint& r) const noexcept { return mint(*this) *= r; }
  constexpr mint operator / (const mint& r) const noexcept { return mint(*this) /= r; }
  constexpr mint& operator += (const mint& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr mint& operator -= (const mint& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr mint& operator *= (const mint& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr mint& operator /= (const mint& r) noexcept {
    int a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      int t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator == (const mint& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const mint& r) const noexcept {
    return this->val != r.val;
  }
  friend ostream& operator << (ostream &os, const mint& x) noexcept {
    return os << x.val;
  }
  friend istream& operator >> (istream &is, mint& x) noexcept {
    return is >> x.val;
  }
  friend constexpr mint powMod(const mint &a, int n) noexcept {
    if (n == 0) return 1;
    auto t = powMod(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};

struct combination {
  vector<mint> fac, finv, inv;

  combination(int n) {
    fac  = vector<mint>(n, 1);
    finv = vector<mint>(n, 1);
    inv  = vector<mint>(n, 1);
    for (int i = 2; i < n; i++) {
      fac[i] = fac[i - 1] * i;
      inv[i] = - inv[MOD % i] * (MOD / i);
      finv[i] = finv[i - 1] * inv[i];
    }
  }

  mint operator()(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
  }
}comb(200020);

signed main() {
  int H, W, K;
  cin >> H >> W >> K;


  mint ave = comb(H*W-1, K-1)*(K-1)/(H*W-1);

  mint ans = 0;

  REP(_, 2){
    mint cnt = 0;
    REP(i, H){
      cnt += comb(H-i, 2)+comb(i+1, 2);
    }
    ans += cnt*ave*W*W;

    swap(H, W);
  }

  cout << ans/2 << "\n";

  return 0;
}
