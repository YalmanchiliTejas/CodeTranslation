#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  vector<long long> sum(n);
  for (int i = n-1; i >= 0; i--) {
    sum[i] = ((i == n-1 ? 0LL : sum[i+1]) + a[i]);
    if (sum[i] >= mod) {
      sum[i] -= mod;
    }
  }
  long long ans = 0;
  for (int i = 0; i+1 < n; i++) {
    ans = (ans + (a[i] * sum[i+1])) %mod;
  }
  cout << ans << '\n';
  return 0;
}