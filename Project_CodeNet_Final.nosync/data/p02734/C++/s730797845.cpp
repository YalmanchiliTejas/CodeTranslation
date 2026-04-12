#include <bits/stdc++.h>
using namespace std;

using ll = long long;
static const ll MOD = 998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, s;
  cin >> n >> s;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  vector<vector<ll>> dp(n + 1, vector<ll>(s + 1));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      dp.at(i + 1).at(j) += dp.at(i).at(j);
      if (j + a.at(i) <= s) {
        if (j == 0) dp.at(i + 1).at(j + a.at(i)) += dp.at(i).at(j) + i;
        else dp.at(i + 1).at(j + a.at(i)) += dp.at(i).at(j);
      }
    }
    for (int j = 0; j <= s; j++) dp.at(i + 1).at(j) %= MOD;
  }
  
  ll ans = 0;
  for (int i = 0; i <= n; i++) ans += dp.at(i).at(s);
  ans %= MOD;
  
  cout << ans << '\n';
}