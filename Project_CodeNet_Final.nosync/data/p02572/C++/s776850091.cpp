#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  long long ans = 0;
  int mod = 1000000007;

  vector<long long> b(n,0);
  b[n-1] = a[n-1];
  for (int i = n-2; i >= 0; i--) {
    b[i] = a[i] + b[i+1];
    b[i] %= mod;
  }

  for (int i = 0; i < n-1; i++) {
    ans += a[i] * b[i+1];
    ans %= mod;
  }

  cout << ans << endl;
}