#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[3000];
ll dp[3000][3000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int l = 1; l <= n; l++) {
    for (int i = 0; i+l <= n; i++) {
      dp[l][i] = max(a[i]-dp[l-1][i+1], a[i+l-1]-dp[l-1][i]);
    }
  }
  cout << dp[n][0] << endl;
}
