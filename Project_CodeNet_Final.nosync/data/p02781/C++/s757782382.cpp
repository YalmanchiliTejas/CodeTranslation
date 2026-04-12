#include <bits/stdc++.h>
using namespace std;

int dp[105][4][2];
bool vis[105][4][2];
string n;

int go(int i, int left, int can) {
  if(left < 0) return 0;
  if(i == (int) n.size()) return (left ? 0 : 1);
  if(vis[i][left][can]) return dp[i][left][can];

  int& ans = dp[i][left][can] = 0;
  if(can) {
    for(int d = 0; d <= 9; ++d) {
      ans += go(i + 1, left - int(d != 0), can);
    }
  } else {
    for(int d = 0; d <= (n[i] - '0'); ++d) {
      ans += go(i + 1, left - int(d != 0), (d == (n[i] - '0') ? 0 : 1));
    }
  }
  vis[i][left][can] = true;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> n >> k;
  cout << go(0, k, 0) << '\n';
}