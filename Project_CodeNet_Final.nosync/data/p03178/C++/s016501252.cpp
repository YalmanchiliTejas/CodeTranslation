#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7
const int mod = (int)1e9+7;

string k; // 999999
int D;

int dp[10010][2][110];

int solve(int id, bool isUp, int sum) {

  if (id == k.size()) {
    if (sum % D == 0) {
      return 1;
    }
    return 0;
  }

  int lim = 9;
  if (isUp) {
    lim = k[id] - '0';
  }

  int &res = dp[id][isUp][sum];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i <= lim; i++) {
    bool tmp = false;
    if (isUp == true && i == lim) {
      tmp = true;
    }
    res += solve(id + 1, tmp, (sum + i) % D);
    res %= mod;
  }
  return res;
};

signed main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);

  cin >> k >> D;

  memset(dp, -1, sizeof dp);
  int res = solve(0, 1, 0) - 1;
  if (res < 0) {
    res += mod;
    res %= mod;
  }
  cout << res << endl;

  return 0;
}