#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 3e3 + 5;
const int mod = 998244353;

ll dp[N][N];
ll pref[N];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, s;
  cin >> n >> s;
  vector < int > a (n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i = 1; i <= n; i++) {
    dp[i][a[i]] = i;
    for (int j = a[i] + 1; j < N; j++) {
      dp[i][j] = pref[j - a[i]];
    }
    for (int j = a[i]; j < N; j++) {
      pref[j] = (pref[j] + dp[i][j]) % mod;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (n - i + 1) * dp[i][s];
    ans %= mod;
  }

  cout << ans << '\n';
}
