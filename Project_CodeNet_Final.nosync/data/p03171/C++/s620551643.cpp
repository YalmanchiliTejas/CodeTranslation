#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

const int N = 3005;

int n;
long long arr[N];
long long dp[N][N][2];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int L = 1; L <= n; L++) {
    for (int i = 0; i + L - 1 < n; i++) {
      int j = i + L - 1;
      for (int p = 0; p < 2; p++) {
        if (L == 1) {
          dp[i][j][p] = arr[i];
        } else if (L == 2) {
          if (p == 0) {
            dp[i][j][p] = max(arr[i] - arr[j], arr[j] - arr[i]);
          } else {
            dp[i][j][p] = min(arr[i] - arr[j], arr[j] - arr[i]);
          }
        } else {
          if (p == 0) {
            long long ans = arr[i] + dp[i + 1][j][1];
            ans = max(ans, dp[i][j - 1][1] + arr[j]);
            dp[i][j][p] = ans;
          } else {
            long long ans = dp[i + 1][j][0] - arr[i];
            ans = min(ans, dp[i][j - 1][0] - arr[j]);
            dp[i][j][p] = ans;
          }
        }
      }
    }
  }
  cout << dp[0][n - 1][0] << endl;
  return 0;
}
