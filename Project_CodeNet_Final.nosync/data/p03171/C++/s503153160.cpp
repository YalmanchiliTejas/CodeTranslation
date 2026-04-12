#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 3010;

int n;
int a[N];
ll dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int sz = 0; sz < n; sz++) {
    for (int l = 0; l+sz < n; l++) {
      int r = l + sz;
      dp[l][r] = max(-dp[l+1][r] + a[l], -dp[l][r-1] + a[r]);
    }
  }
  cout << dp[0][n-1] << nl;
  return 0;
}
