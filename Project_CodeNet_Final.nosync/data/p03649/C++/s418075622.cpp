#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long ret = 0;
  long long minv = 9e18;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    minv = min(minv, a[i]);
  }
  for (int i = 0; i < n; i++) {
    long long tmp = (a[i] - minv) / (n + 1);
    ret += tmp;
    a[i] -= tmp * (n + 1);
  }
  for (int i = 0; i < n; i++) a[i] += ret;
  minv += ret;
  long long d = minv - (n - 1);
  if (d > 0) {
    for (int i = 0; i < n; i++) a[i] -= d;
    ret += d * n;
    minv -= d;
  }
  int maxv = 0;
  int maxi;
  for (int i = 0; i < n; i++) {
    if (maxv < a[i]) {
      maxv = a[i];
      maxi = i;
    }
  }
  while (maxv >= n) {
    for (int i = 0; i < n; i++) a[i]++;
    ret++;
    a[maxi] -= (n + 1);
    maxv = 0;
    for (int i = 0; i < n; i++) {
      if (maxv < a[i]) {
        maxv = a[i];
        maxi = i;
      }
    }
  }
  cout << ret << '\n';
  return 0;
}