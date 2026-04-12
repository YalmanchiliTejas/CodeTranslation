#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int a[3003];
ll dp[3003][3003];

ll find(int l, int r) {
  if (r < l) return 0;
  if (dp[l][r] == -1) {
    if ((r - l) % 2 == (n - 1) % 2) {
      dp[l][r] = max(a[l] + find(l + 1, r), a[r] + find(l, r - 1));
    } else {
      dp[l][r] = min(-a[l] + find(l + 1, r), -a[r] + find(l, r - 1));
    }
  }
  return dp[l][r];
}

int main() {
  ios::sync_with_stdio(false);
  // cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << find(0, n - 1) << '\n';

  return 0;
}