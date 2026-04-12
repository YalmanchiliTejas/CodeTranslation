#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> pref(n);
  const int MOD = 1e9 + 7;
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] += pref[i - 1] + a[i];
    pref[i] %= MOD;
  }
  // const int MOD = 1e9 + 7;
  int res = 0;
  for (int i = 0; i < n; i++) { 
    res += (a[i] % MOD * (pref[n - 1] - pref[i]) % MOD) % MOD;
    res %= MOD;
  }   
  cout << (res + MOD) % MOD << '\n';
  return 0;
}
