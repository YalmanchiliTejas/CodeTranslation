#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const int maximum = 2e5+1;

void solve() {
  int n;
  long long sum = 0;
  int a[maximum] = {};
  long long ans = 0;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  for(int i = n-1; i >= 0; i--) {
    sum -= a[i];
    ans += ((sum % mod) * a[i]) % mod;
    ans %= mod;
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0);
	ios::sync_with_stdio(false);
  solve();
  return 0;
}