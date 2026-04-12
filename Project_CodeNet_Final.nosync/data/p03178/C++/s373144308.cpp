#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int D = 105;
const int MOD = 1e9 + 7;

string k;
int d;
int dp[N][D][2];

int solve(int pos, int modd, int kurang) {
  if (pos == -1) {
    return modd == 0;
  }

  int &ret = dp[pos][modd][kurang];
  if (ret != -1) return ret;
  ret = 0;

  if (kurang) {
    for (int i = 0 ; i < 10 ; i++) {
      ret = (ret + solve(pos-1, (modd + i) % d, kurang)) % MOD;
    }
  } else {
    for (int i = 0 ; i <= k[pos]-'0' ; i++) {
      ret = (ret + solve(pos-1, (modd + i) % d, i < k[pos] - '0')) % MOD;
    }
  }

  // printf("pos %d modd %d kurang %d -> %d\n", pos, modd, kurang, ret);
  return ret;
}

int main() {
  cin >> k >> d;
  reverse(k.begin(), k.end());

  memset(dp, -1, sizeof dp);
  int ret = (solve(k.length()-1, 0, 0) + MOD - 1) % MOD;
  cout << ret << endl;
  return 0;
}