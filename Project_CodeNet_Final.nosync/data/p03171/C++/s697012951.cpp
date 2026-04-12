// https://atcoder.jp/contests/dp/tasks/dp_l

#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mp make_pair
#define mod 1000000007
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
void init() {
  int n;
  cin >> n;
  vector<int> points(n);
  for (int &i : points)
    cin >> i;
  vector<vector<int>> dp(n, vector<int>(n));
  // dp[l][r] --> X-Y considering game played only between l and r
  // dp[l][r] = max(points[l]-dp[l+1][r],points[r]-dp[l][r-1])
  for (int l = n-1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r)
        dp[l][r] = points[l];
      else
        dp[l][r] = max(points[l] - dp[l + 1][r], points[r] - dp[l][r - 1]);
    }
  }
  cout<<dp[0][n-1]<<endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
