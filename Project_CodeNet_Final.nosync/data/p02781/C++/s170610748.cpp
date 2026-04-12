#include <bits/stdc++.h>
using namespace std;
#define long long long
#define read cin >>
#define echo cout <<
#define fin << endl
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)

// for debug macro
bool global_debug_flag = true;
#define DEBUG(val) \
  if (global_debug_flag) cout << #val << " = " << val << endl

int dp[105][2][105];

int rec(string &s, int D, int keta = 0, bool tight = true, int sum = 0) {
  if (keta == s.size()) {
    // sum??????????(sum == D)?1???
    // ????????0???
    return sum == D;
  }

  int x = s[keta] - '0';
  int r = tight ? x : 9;
  int res = 0;
  // -1??????????????????????????????
  if (dp[keta][tight][sum] != -1) {
    return dp[keta][tight][sum];
  } else {
    for (int i = 0; i <= r; i++) {
      if (i == 0) {
        res += rec(s, D, keta + 1, tight && i == r, sum);
      } else {
        res += rec(s, D, keta + 1, tight && i == r, sum + 1);
      }
    }
  }
  dp[keta][tight][sum] = res;
  return res;
}

int main() {
  memset(dp, -1, sizeof(dp));
  string s;
  read s;
  int k;
  read k;
  // cout << dp[s.size()][0][k] + dp[s.size()][1][k] << endl;
  cout << rec(s, k) << endl;
}
