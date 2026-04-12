#include <algorithm>
#include <iostream>
using namespace std;
int dp[100005], a[100005], n;
int LIS_nlgn() {
  int len = 1;dp[0] = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] >= dp[len - 1]) dp[len++] = a[i];
    else {
      *upper_bound(dp, dp + len, a[i]) = a[i];
    }
  }
  return len;
}
int main() {
  cin >> n;
  for (int i = n - 1; i >= 0; i--) cin >> a[i];
  cout << LIS_nlgn() << endl;
}