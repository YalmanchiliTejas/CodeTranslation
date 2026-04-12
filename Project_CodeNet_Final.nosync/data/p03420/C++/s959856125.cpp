#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0); cin.sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  if (!k) {
    cout << n * n << endl;
    return 0;
  }
  long long ret = 0;
  for (int b = k + 1; b <= n; b++) {
    ret += n + 1 - (k * (n / b) + min(k, n % b + 1));
  }
  cout << ret << endl;
  return 0;
}