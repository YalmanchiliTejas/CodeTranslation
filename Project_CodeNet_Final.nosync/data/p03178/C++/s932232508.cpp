#include <bits/stdc++.h>

using namespace std;

const int MAX_POS = 1e4 + 10, MAX_SUM = 110, MOD = 1e9 + 7;

inline void add (int& a, int b) { a = (a + b) % MOD; }

string K;
int D;
int memo[MAX_POS][MAX_SUM][2];

int dp (int pos, int sum, int lt) {
  if (pos == int(K.size())) return sum == 0;
  int& ret = memo[pos][sum][lt];
  if (~ret) return ret;
  ret = 0;
  if (lt) {
    for (int d = 0; d <= 9; d++) {
      add(ret, dp(pos + 1, (sum + d) % D, lt));
    }
  }
  else {
    for (int d = 0; d <= K[pos]; d++) {
      add(ret, dp(pos + 1, (sum + d) % D, d < K[pos]));
    }
  }
  return ret;
}

int main () {
  cin >> K >> D;
  for (char& ch: K) ch -= '0';
  memset(memo, -1, sizeof memo);
  cout << (dp(0, 0, 0) + MOD - 1) % MOD << endl;
  return (0);
}
