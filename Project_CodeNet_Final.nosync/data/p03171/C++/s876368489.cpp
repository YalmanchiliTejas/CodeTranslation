#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll dp[3010][3010], a[3010], v[3010][3010];
ll n;

ll f(int l, int r) {
  if (l > r) return 0;
  if (v[l][r]) return dp[l][r];
  v[l][r] = 1;

  ll res;
  ll turn = n - 1 - (r - l);
  if (turn % 2 == 0) {
    res = -INF;
    res = max(res, f(l + 1, r) + a[l]);
    res = max(res, f(l, r - 1) + a[r]);
  } else {
    res = INF;
    res = min(res, f(l + 1, r) - a[l]);
    res = min(res, f(l, r - 1) - a[r]);
  }
  return dp[l][r] = res;
}

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];

  cout << f(0, n - 1) << endl;
   return 0;
}