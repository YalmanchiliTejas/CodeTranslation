#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
typedef long long ll;

int flag[3000][3000];

ll solve(int i, int j, vector <vector<ll>> &dp, vector<int> &a) {
  if (flag[i][j] != 0) {
    return dp[i][j];
  }
  if (i == j) {
    dp[i][j] = a[i];
  } else {
    dp[i][j] = max(a[i] - solve(i+1, j, dp, a), a[j] - solve(i, j-1, dp, a));
  }
  flag[i][j] = 1;
  return dp[i][j];
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<ll>> dp(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << solve(0, n-1, dp, a) << endl;
}
