#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef long long llt;

const int MaxN = 10000 + 5, MaxD = 100 + 5;
const llt Mod = 1e9 + 7;

string K;
int N, D;
int A[MaxN];
llt dp[MaxN][MaxD][2];
bool vis[MaxN][MaxD][2];

void init() {
  cin >> K >> D;
  N = K.length();
  for (int i = 1; i <= N; ++i) A[i] = K[i - 1] - '0';
}

// 到了第 x 高位，数字和在模 D 意义下和为 d，是否有上限
llt dfs(int x, int d, int lim) {
  if (x > N) {
    if (d == 0) return 1;
    else return 0;
  }
  if (vis[x][d][lim] == true) return dp[x][d][lim];
  vis[x][d][lim] = true;

  if (lim == 0) {
    for (int i = 0; i <= 9; ++i) {
      int s = (d + i) % D;
      dp[x][d][lim] = (dp[x][d][lim] + dfs(x + 1, s, 0)) % Mod;
    }
  } else {
    for (int i = 0; i < A[x]; ++i) {
      int s = (d + i) % D;
      dp[x][d][lim] = (dp[x][d][lim] + dfs(x + 1, s, 0)) % Mod;
    }
    int s = (d + A[x]) % D;
    dp[x][d][lim] = (dp[x][d][lim] + dfs(x + 1, s, 1)) % Mod;
  }
  return dp[x][d][lim];
}

void solve() {
  llt ans = dfs(1, 0, 1);

  ans = ((ans - 1) % Mod + Mod) % Mod;
  cout << ans << endl;
}

int main() {
  init();
  solve();
  return 0;
}