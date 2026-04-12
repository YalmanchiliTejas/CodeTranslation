#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ret = 0;
  while (true) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (a[i] >= n) {
        flag = true;
        long long d = a[i] / n;
        ret += d;
        for (int j = 0; j < n; j++) a[j] += d;
        a[i] -= d * (n + 1);
      }
    }
    if (!flag) break;
  }
  cout << ret << '\n';
  return 0;
}