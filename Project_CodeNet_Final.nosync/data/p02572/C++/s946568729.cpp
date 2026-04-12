#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  long long ans = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    sum %= mod;
  }
  for (int i = 0; i < n; i++) {
    sum += mod;
    sum -= a[i];
    sum %= mod;
    ans += (a[i] * sum) % mod;
  }
  cout << ans % mod << endl;
  return 0;
}