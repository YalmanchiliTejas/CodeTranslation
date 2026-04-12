#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3010;
const int mod = 998244353;

int n, s, arr[N];
ll dp[N][N][3];
bool vis[N][N][3];

ll fun(int pos, int rem, int f) {
  //f = 0, when neither L or R has been taken
  //f = 1, when L has been taken but not R
  //f = 2, when both L and R have been taken
  if (pos > n) return (rem == 0 && f == 2);
  ll &ret = dp[pos][rem][f];
  if (vis[pos][rem][f]) return ret;
  vis[pos][rem][f] = true;
  ret = 0;
  if (f == 2) {
    ret = (ret + fun(pos + 1, rem, f)) % mod;
  } else {
    if (f == 0) {
      ret = (ret + fun(pos + 1, rem, f) + fun(pos + 1, rem, 1)) % mod;
      if (arr[pos] <= rem) ret = (ret + fun(pos + 1, rem - arr[pos], 1) + fun(pos + 1, rem - arr[pos], 2)) % mod;
    } else {
      ret = (ret + fun(pos + 1, rem, 1)) % mod;
      ret = (ret + fun(pos + 1, rem, 2)) % mod;
      if (arr[pos] <= rem) ret = (ret + fun(pos + 1, rem - arr[pos], 1) + fun(pos + 1, rem - arr[pos], 2)) % mod;
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  cout << fun(1, s, 0) << '\n';
}