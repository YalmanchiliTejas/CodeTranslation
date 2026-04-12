#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, s;
int a[3000];
long dp[3001];
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int k = s - 1; k >= 0; --k) {
      int nk = k + a[i];
      if (nk > s) continue;
      long del = dp[k];
      if (k == 0) del = del * (i + 1) % mod;
      if (nk == s) del = del * (n - i) % mod;
      dp[nk] += del;
      dp[nk] %= mod;
    }
  }
  cout << dp[s] << endl;
}