#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  int x, m;
  cin >> n >> x >> m;
  vector<int> ind(m, -1), a;
  int len = 0;
  long long pre_sum = 0;
  while (ind[x] == -1) {
    a.emplace_back(x);
    ind[x] = len++;
    pre_sum += x;
    x = (long long)x * x % m;
  }
  int nc = len - ind[x];
  long long ans = 0;
  if (n <= len) {
    for (int i = 0; i < n; i++) {
      ans += a[i];
    }
  } else {
    ans += pre_sum;
    n -= len;
    long long cyc_sum = 0, rem_sum = 0;
    int r = n % nc;
    for (int i = ind[x]; i < len; i++) {
      cyc_sum += a[i];
      if (i < ind[x] + r) {
        rem_sum += a[i];
      }
    }
    ans += cyc_sum * (n / nc) + rem_sum;
  }
  cout << ans << '\n';
  return 0;
}