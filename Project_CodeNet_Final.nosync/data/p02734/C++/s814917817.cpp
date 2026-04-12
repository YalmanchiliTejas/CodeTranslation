#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
const int mod = 998244353;  

signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int n, s; cin >> n >> s;
  vector<int> v;
  copy_n(istream_iterator<int>(cin), n, back_inserter(v));

  vector<int> dp(s+1);
  for (int i = 0; i < n; ++i) {
    int x = v[i];
    if (x == s)
      (dp[s] += (i+1)*(n-i)) %= mod;
    else if (x < s)
      (dp[s] += dp[s-x]*(n-i)) %= mod;
    for (int k = s-1; k > x; --k)
      (dp[k] += dp[k-x]) %= mod;
    if (x < s)
      (dp[x] += i+1) %= mod;
  }
  cout << dp[s] << '\n';
}

