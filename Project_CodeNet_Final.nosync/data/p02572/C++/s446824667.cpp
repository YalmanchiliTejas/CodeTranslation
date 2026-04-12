#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5;
const int mod = 1e9 + 7;

int main () {
  int n, a[nmax+1], s[nmax+1], ans = 0;
  cin >> n;
  s[0] = 0;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    s[i] = (s[i-1] + a[i]) % mod;
  }
  for (int i=1; i<=n; ++i) {
    int sum = s[n] - s[i] < 0 ? s[n] - s[i] + mod : s[n] - s[i];
    int to_add = ((long long)a[i] * (long long)sum) % (long long)mod;
    ans = (ans + to_add) % mod;
  }
  cout << ans;
  return 0;
}
