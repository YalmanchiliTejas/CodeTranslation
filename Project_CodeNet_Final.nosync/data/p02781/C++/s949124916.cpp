#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
#define mins(x, y) (x = min(x, y))
#define maxs(x, y) (x = max(x, y))
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using P = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

ll dp[105][2][2][2][2]; // [i:今いる桁][j:未満フラグ][s1][s2][s3]
void solve() {
  string N;
  cin >> N;
  int k;
  cin >> k;
  int len = N.size();
  dp[0][0][0][0][0] = 1;
  rep(i, len) rep(j, 2) rep(s1, 2) rep(s2, 2) rep(s3, 2) {
    int d = N[i] - '0';
    rep(x, 10) { // 0-9まで回して遷移をさせる
      int nj = j, ns1 = s1, ns2 = s2, ns3 = s3;
      if (!j && d < x) continue;
      if (x < d) nj = 1;
      if (!ns1 && !ns2 && !ns3 && x != 0) ns1 = 1, ns2 = 0, ns3 = 0;
      else if (ns1 && !ns2 && !ns3 && x != 0) ns1 = 0, ns2 = 1, ns3 = 0;
      else if (ns2 && !ns3 && x != 0) ns1 = 0, ns2 = 0, ns3 = 1;
      else if (ns3 && x != 0) continue;
      dp[i + 1][nj][ns1][ns2][ns3] += dp[i][j][s1][s2][s3];
    }
  }
  int ans = 0;
  if (k == 1) {
    rep(j, 2) ans += dp[len][j][1][0][0];
  } else if (k == 2) {
    rep(j, 2) ans += dp[len][j][0][1][0];
  } else {
    rep(j, 2) ans += dp[len][j][0][0][1];
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}