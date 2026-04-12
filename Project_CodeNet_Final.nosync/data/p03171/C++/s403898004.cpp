#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int n;
vector<ll> a(3005);
ll dp[3005][3005];

ll rec(int l, int r) {
  if (l == r)
    return 0;

  if (dp[l][r])
    return dp[l][r];

  if ((n - (r - l)) % 2 == 0) {
    dp[l][r] = max(rec(l + 1, r) + a[l], rec(l, r - 1) + a[r - 1]);
  } else {
    dp[l][r] = min(rec(l + 1, r) - a[l], rec(l, r - 1) - a[r - 1]);
  }

  return dp[l][r];
}

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];
  cout << rec(0, n) << endl;
  return 0;
}
