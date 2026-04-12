#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  long long count = 0;

  for (int b = 1; b <= n; b++) {
    int r = n % b;
    count += n / b * max(0, (b - k)) + max(0, r - k + 1);
  }
  if (k == 0) count -= n;

  cout << count;
}