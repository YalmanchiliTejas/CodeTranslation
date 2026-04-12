#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int d[105] = {0};
int point[20] = {0};
int dp[1000000] = {0};
int memo[105][105] = {0};
queue<int> qu;

int solve();

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i) d[i] = -1;
  for(int i = 0; i < m; ++i) {
    cin >> point[i];
    --point[i];
    d[point[i]] = i;
  }
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < k; ++j) {
      cin >> memo[i][j];
      --memo[i][j];
    }
  cout << solve() << endl;
}

int solve() {
  int now, nextn;
  qu.push((1 << m) - 1);
  dp[(1 << m) - 1] = 0;
  while(qu.size() > 0) {
    now = qu.front();
    qu.pop();
    for(int i = 0; i < k; ++i) {
      nextn = 0;
      for(int j = 0; j < m; ++j)
        if(((1 << j) & now) == (1 << j)) {
          int np = point[j];
          int x = memo[np][i], bit;
          if(d[x] == -1) continue;
          bit = (1 << d[x]);
          nextn |= bit;
        }
      if(nextn != (1 << m) - 1 && dp[nextn] == 0) {
        dp[nextn] = dp[now] + 1;
        qu.push(nextn);
      }
    }
  }
  return dp[0];
}
