#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define inf (int)1e18+7

int n;
int a[3003];
int dp[2][3003][3003];
bool used[2][3003][3003] = {false};

int solve(int who, int beg, int fin) {
  if (beg > fin) return 0;
  if (used[who][beg][fin]) return dp[who][beg][fin];
  int res;
  if (who == 0) {
    res = solve(who ^ 1, beg + 1, fin) + a[beg];
    res = max(res, solve(who ^ 1, beg, fin - 1) + a[fin]);
  } else {
    res = solve(who ^ 1, beg + 1, fin) - a[beg];
    res = min(res, solve(who ^ 1, beg, fin - 1) - a[fin]);
  }
  used[who][beg][fin] = true;
  dp[who][beg][fin] = res;
  return res;
}


signed main() {

  cin >> n;
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
  }

  int res = solve(0, 0, n - 1);
  cout << res << endl;


  return 0;
}