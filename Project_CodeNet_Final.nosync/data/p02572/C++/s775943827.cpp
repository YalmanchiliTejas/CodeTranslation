#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

const int maxn = 1e6;

long long mod(long long value) {
  if (value >= 0) {
    return value % MOD;
  }
  for (int i = 1; ; i++) {
    long long tmp = value + i * MOD;
    if (tmp >= 0) {
      return tmp;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> sum(maxn, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long tmp = 0;
  for (int i = n - 1; i >= 1; i--) {
    tmp += a[i];
    sum[i] = tmp;
    if (sum[i] >= MOD) {
      sum[i] = mod(sum[i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += a[i] * sum[i + 1];
    if (ans >= MOD) {
      ans = mod(ans);
    }
  }
  cout << ans << '\n';
  return 0;
}
