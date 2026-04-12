#include <bits/stdc++.h>

using namespace std;
using Int = long long;

const int nax = 3005;
Int dp[nax][nax][2];
Int ar[nax];

Int rec(int i, int j, int p) {
  if(i == j) {
    return (p ? -1 : 1) * ar[i];
  }
  Int &x = dp[i][j][p];
  if(x != -1) {
    return x;
  } 
  x = 0;
  if(!p) {
    x = max(ar[i] + rec(i + 1, j, 1), ar[j] + rec(i, j - 1, 1));
  } else {
    x = min(-ar[i] + rec(i + 1, j, 0), -ar[j] + rec(i, j - 1, 0));
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> ar[i];
  }
  memset(dp, -1 ,sizeof dp);
  cout << rec(0, n - 1, 0) << '\n';
  return 0;
}
