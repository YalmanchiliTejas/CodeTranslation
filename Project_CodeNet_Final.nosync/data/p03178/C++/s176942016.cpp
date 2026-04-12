#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using VVVll = vector<VVll>;
using VVVld = vector<VVld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


int main() {
  string K; cin >> K;
  int D; cin >> D;
  int n = K.size();

  VVll dp(n, Vll(D));
  dp[0][0] = 1;
  rep(i, n-1) rep(d, D) rep(k, 10) {
    (dp[i+1][(d+k)%D] += dp[i][d]) %= MOD;
  }

  int sum = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = K[i] - '0';
    for (int d = 0; d < x; ++d) {
      int y = (sum + d) % D;
      (ans += dp[n-i-1][(D-y)%D]) %= MOD;
    }
    (sum += x) %= D;
  }

  if (sum == 0) ans++;
  (ans += MOD - 1) %= MOD;
  cout << ans << endl;
  return 0;
}
