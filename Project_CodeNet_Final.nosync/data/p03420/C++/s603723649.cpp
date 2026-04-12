#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  long long cnt = 0;
  for (int i = 1; i <= n; i++) { // b
    cnt += (n + 1) / i * min((long long)i, k) + min((n + 1) % i, k);
    if (k != 0) cnt--;
  }
  cout << n * n - cnt << '\n';
  return 0;
}