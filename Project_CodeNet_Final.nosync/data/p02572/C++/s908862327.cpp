#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), ps(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ps[i + 1] = (ps[i] + a[i]) % mod;
    if (ps[i + 1] < 0) {
      ps[i + 1] += mod;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int sum = (ps[n] - ps[i + 1]) % mod;
    if (sum < 0) {
      sum += mod;
    }
    sum = ((long long)a[i] * sum) % mod;
    if (sum < 0) {
      sum += mod;
    }
    ans = (ans + sum) % mod;
  }
  cout << ans << '\n';
  return 0;
}