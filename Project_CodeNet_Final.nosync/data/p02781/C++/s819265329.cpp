#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3000;
int dp[maxn][4][2];
char N[maxn];
string s;
int k, len;

inline int dfs (int idx, int c0, int flag) {
  if (c0 > k) return 0; // hit max number of 0s
  if (idx > len) return c0 == k; // out of bounds, return 1 if capacity is met
  if (dp[idx][c0][flag] != -1) return dp[idx][c0][flag];
  int ans = 0;
  int bound = (flag == 1) ? N[idx] - '0' : 9;
  for (int i = 0; i <= bound; i++) {
    ans += dfs(idx + 1, c0 + (i != 0), flag && (i == bound));
  }
  return dp[idx][c0][flag] = ans;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, 255, sizeof(dp));

  // index the number N (string) from 1
  cin >> s;
  len = s.size();
  for (int i = 0; i < len; i++) N[i + 1] = s[i];
  len = strlen(N + 1);
  cin >> k;

  // start at 1st char, count of 0s is 0, flag set (bounded)
  cout << dfs(1, 0, 1) << endl;
  return 0;
}
