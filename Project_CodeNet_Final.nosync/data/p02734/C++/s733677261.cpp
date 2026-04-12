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
/* const int MOD = 1000000007; */
const int MOD = 998244353;
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

struct mint {
  int val;
  mint(int v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  int getMOD() { return MOD; }
  mint operator - () const noexcept {
    return val ? MOD - val : 0;
  }
  mint operator + (const mint& r) const noexcept { return mint(*this) += r; }
  mint operator - (const mint& r) const noexcept { return mint(*this) -= r; }
  mint operator * (const mint& r) const noexcept { return mint(*this) *= r; }
  mint operator / (const mint& r) const noexcept { return mint(*this) /= r; }
  mint& operator += (const mint& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  mint& operator -= (const mint& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  mint& operator *= (const mint& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  mint& operator /= (const mint& r) noexcept {
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
  bool operator == (const mint& r) const noexcept {
    return this->val == r.val;
  }
  bool operator != (const mint& r) const noexcept {
    return this->val != r.val;
  }
  friend ostream& operator << (ostream &os, const mint& x) noexcept {
    return os << x.val;
  }
  friend istream& operator >> (istream &is, mint& x) noexcept {
    return is >> x.val;
  }
  friend mint powMod(const mint &a, int n) noexcept {
    if (n == 0) return 1;
    auto t = powMod(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};


signed main() {
  int N, S; 
  cin >> N >> S;

  vector<int> A(N);
  REP(i, N) cin >> A[i];


  vector<mint> dp(S+1);

  mint ans = 0;
  REP(i, N){
    dp[0] += 1;
    RREP(j, S+1){
      if(j+A[i] <=S) dp[j+A[i]] += dp[j];
    }
    ans += dp[S];
  }

  cout << ans << "\n";

  return 0;
}