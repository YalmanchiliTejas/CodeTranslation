#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  vector<vl> dp(n + 5, vl(3, -1e18));
  int k = n % 2 + 1;
  dp[0][k] = 0;
  rep(i, n) rep(j, 3) {
    if(dp[i][j] == -1e18) continue;
    if(j == 2) dp[i + 2][0] = max(dp[i + 2][0], dp[i][j]);
    if(j >= 1) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
    dp[i + 2][j] = max(dp[i + 2][j], dp[i][j] + a[i]);
  }
  ll ans = -1e18;
  rep2(i, n, n + 2) rep(j, 2) ans = max(ans, dp[i][j]);
  cout << ans << endl;
}