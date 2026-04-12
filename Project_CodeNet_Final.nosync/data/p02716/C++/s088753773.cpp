#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define int ll
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;

template<typename T>
ostream& operator<<(ostream& o, const vector<T>& v) {
  o << "[";
  for (const T& x : v)
    o << x << ",";
  return o << "]";
}

const int INF = 1e18;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vi as(n);
  for (int& ai: as)
    cin >> ai;

  vvi dp(3, vi(n, -INF));
  dp[0][0] = as[0];
  dp[1][1] = as[1];
  dp[2][2] = as[2];
  for (int k=0; k<3; ++k) {
    for (int p=0; p<n; ++p) {
      if (p >= 2)
        dp[k][p] = max(dp[k][p], dp[k][p-2] + as[p]);
      for (int off=1; off<=k && (p-off-2)>=0; ++off)
        dp[k][p] = max(dp[k][p], dp[k-off][p-off-2] + as[p]);
    }
  }
  //cerr << "DBG " << dp << endl;
  int sol;
  if (n%2 == 0) {
    sol = dp[1][n-1];
    if (n-2 >= 0)
      sol = max(sol, dp[0][n-2]);
  } else {
    sol = dp[2][n-1];
    if (n-2 >= 0)
      sol = max(sol, dp[1][n-2]);
    if (n-3 >= 0)
      sol = max(sol, dp[0][n-3]);
  }
  cout << sol << endl;
}
