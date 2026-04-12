#include <bits/stdc++.h>
using namespace std;

#define UNIQUE(v) sort(all(v)),v.erase(unique(all(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e16;
const int N = 3e3 + 5;

LL a[ N ];
LL dp[ N ][ N ];

LL solve(int l, int r) {
  if (l > r) return 0;
  if (dp[l][r] != -INF) return dp[l][r];
  LL ret = -INF;
  ret = max(ret, a[l] - solve(l + 1, r));
  ret = max(ret, a[r] - solve(l, r - 1));
  return dp[l][r] = ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = -INF;
    }
  }
  cout << solve(1, n) << endl;
  return 0;
}
