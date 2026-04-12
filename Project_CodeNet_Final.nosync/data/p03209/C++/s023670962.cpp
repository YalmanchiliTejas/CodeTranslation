#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// 0->バンの数, 1->パティの数
ll dp[55][2] = {};

// パティの数を返す
ll bg(ll level, ll sou) {
  if (level == 0) return 1;

  if (sou == 1)
    return 0;
  else if (sou < dp[level - 1][0] + 2)
    return bg(level - 1, sou - 1);
  else if (sou == dp[level - 1][0] + 2)
    return dp[level - 1][1] + 1;
  else if (sou < dp[level][0])
    return dp[level - 1][1] + 1 + bg(level - 1, sou - dp[level - 1][0] - 2);
  else
    return dp[level][1];
}

int main() {
  ll level, sou;
  cin >> level >> sou;

  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i = 1; i <= level; i++) {
    dp[i][0] = dp[i - 1][0] * 2 + 3;
    dp[i][1] = dp[i - 1][1] * 2 + 1;
  }

  cout << bg(level, sou) << endl;
}
