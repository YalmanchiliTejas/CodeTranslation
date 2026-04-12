#include "bits/stdc++.h"

using namespace std;

const int MAX_N = 5000;

// dp[i][j] := i を含み, 公差 v[i]-v[j] の数列の長さ
vector<vector<int>> dp(MAX_N, vector<int>(MAX_N, 0));

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  map<int, int> pos;
  for (int i = 0; i < n; i++) pos[v[i]] = i;
  int ret = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dif = v[i] - v[j];
      if (pos.count(v[j] - dif)) {
        int p = pos[v[j] - dif];
        dp[i][j] = dp[j][p] + 1;
      } else {
        dp[i][j] = 2;
      }
      ret = max(ret, dp[i][j]);
    }
  }
  cout << ret << endl;
}

