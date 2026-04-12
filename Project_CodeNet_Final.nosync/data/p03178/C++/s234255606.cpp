#include <bits/stdc++.h>
using namespace std;
#define long long long
#define read cin >>
#define echo cout <<
#define fin << endl
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)

// for debug macro
bool global_debug_flag = false;
#define DEBUG(val) \
  if (global_debug_flag) cout << #val << " = " << val << endl

// dp[max_keta][tight_flag 基本は2値][condition_flag ここで条件をカウント]
int dp[100005][2][105];
long mod = 1000000007;
// 前提：globalにメモ化のdp配列が定義されていること(かつ-1で初期化されていること)
// このtemplateは各桁の和がDになるものを集めてくる。
long rec(string &s, int D, int keta = 0, bool tight = true, int sum = 0) {
  if (keta == s.size()) {
    // sumが条件を満たした場合(sum == D)に1を返してカウント扱い。
    // 満たさなかったら0を返却。
    return sum % D == 0;
  }

  int x = s[keta] - '0';
  int r = tight ? x : 9;
  long res = 0;
  // -1で初期化しているので、すでに値が求められていた場合は即返す。
  if (dp[keta][tight][sum] != -1) {
    return dp[keta][tight][sum];
  } else {
    for (int i = 0; i <= r; i++) {
      // 下位桁に渡す。ここでsumの値を調整して条件に合うやつを集めてくる
      res += rec(s, D, keta + 1, tight && i == r, (sum + i) % D) % mod;
      res %= mod;
    }
  }

  dp[keta][tight][sum] = res;
  return res;
}

int main() {
  memset(dp, -1, sizeof(dp));
  string s;
  cin >> s;
  int d;
  cin >> d;
  cout << (rec(s, d) - 1 + mod) % mod << endl;
}