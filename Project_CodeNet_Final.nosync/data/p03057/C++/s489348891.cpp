#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <chrono>
#include <ctime>
#include <cassert>
#include <bitset>
#include <iterator>
#include <cmath>
#include <stack>
#include <random>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//constexpr ll mod = 998244353;
constexpr ll mod = 1e9+7;
const double PI = acos(-1.0);
mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  string s; cin >> s;

  char c0 = s[0];
  bool same = true;
  rep(i, m) {
    if (s[i] != c0) {
      same = false;
      break;
    }
  }
  
  if (same) {
    // 0: s[0] = c[0] && s[i] = c[0]
    // 1: s[0] = c[0] && s[i] != c[0]
    // 2: s[0] != c[0] && s[i] = c[0]
    // 3: s[0] != c[0] && s[i] != c[0]
    vector<ll> dp1(4); 
    vector<ll> dp2(4);
    dp1[0] = 1;
    dp1[3] = 1;
    for(int i=1; i<n-1; i++) {
      dp2[0] = dp1[0] + dp1[1];
      dp2[0] %= mod;
      dp2[1] = dp1[0];
      dp2[2] = dp1[2] + dp1[3];
      dp2[2] %= mod;
      dp2[3] = dp1[2];
      rep(j, 4) {
        dp1[j] = dp2[j];
        //debug(j);debugln(dp1[j]);
      }
    }
    ll ans = 0;
    ans += dp1[0] + dp1[1];
    ans += dp1[0];
    ans += dp1[2] + dp1[3];
    cout << ans%mod << endl;
    return 0;
  }

  if (n%2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  char before = c0;
  int cnt = 0;
  int minfirst = INT_MAX;
  int minodd = INT_MAX;
  rep(i, m) {
    if (s[i] == c0) {
      cnt++;
    } else {
      if (minfirst == INT_MAX) {
        chmin(minfirst, cnt);
      }
      if (cnt&1) {
        chmin(minodd, cnt);
      }
      cnt = 0;
    }
  }

  cnt = INT_MAX;
  if (minfirst%2 == 0) {
    chmin(cnt, minfirst+1);
  }
  chmin(cnt, minodd);
  int p = (cnt-1)/2;
  //debugln(p);
  n = n/2;
  
  vector<ll> dp(n+1);
  vector<ll> rdp(n+1);
  dp[1] = 1; rdp[1] = 1;
  dp[2] = 1; rdp[2] = 2;
  for(int i=3; i<=n; i++) {
    dp[i] = rdp[i-1] - rdp[max(0, i-p-2)] + mod;
    dp[i] %= mod;
    rdp[i] = rdp[i-1] + dp[i];
    rdp[i] %= mod;
    //debug(i); debugln(dp[i]);
  }

  ll ans = 0;
  for(ll L=0; L<=p && L<n; L++) {
    //debug(L); debugln(dp[max(0LL, n-L)]);
    ans += dp[max(0LL, n-L)]*(L+1)*2;
    ans %= mod;
  }
  cout << ans << endl;
}