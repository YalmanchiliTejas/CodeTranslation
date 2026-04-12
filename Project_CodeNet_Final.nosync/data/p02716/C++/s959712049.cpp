#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using Vbo = vector<bool>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using VVbo = vector<Vbo>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> e; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << " "; return os; }
template<typename T> inline int count_between(vector<T> &a, T l, T r) { return lower_bound(all(a), r) - lower_bound(all(a), l); } // [l, r)
inline int Log2(ll x) { int k; for (k = 0; x > 0; ++k) x >>= 1; return k; } // number of binary digits
const int INF  = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS   = 1e-10;
const int MOD  = int(1e9)+7;


int main() {
  ll n; cin >> n;
  Vll a(n); cin >> a;

  ll m = n/2;

  if (n % 2 == 1) {
    VVll dp(m+1, Vll(3));
    rep(i, m) {
      dp[i+1][2] =      dp[i][2] + a[2*i+2];
      chmax(dp[i+1][2], dp[i][1] + a[2*i+2]);
      chmax(dp[i+1][2], dp[i][0] + a[2*i+2]);

      dp[i+1][1] =      dp[i][1] + a[2*i+1];
      chmax(dp[i+1][1], dp[i][0] + a[2*i+1]);
      
      dp[i+1][0] =      dp[i][0] + a[2*i];
    }

    ll ans = *max_element(all(dp[m]));
    cout << ans << endl;
  }
  else {
    VVll dp(m+1, Vll(2));
    rep(i, m) {
      dp[i+1][1] =      dp[i][1] + a[2*i+1];
      chmax(dp[i+1][1], dp[i][0] + a[2*i+1]);
      
      dp[i+1][0] =      dp[i][0] + a[2*i];
    }

    ll ans = *max_element(all(dp[m]));
    cout << ans << endl;
  }
  return 0;
}
