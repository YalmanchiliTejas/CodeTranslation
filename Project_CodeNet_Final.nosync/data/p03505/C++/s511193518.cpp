#include <bits/stdc++.h>
using namespace std;

long long k, a, b;

int main() {
  cin >> k >> a >> b;
  b *= -1;

  if (k <= a) {
    cout << 1 << endl;
    return 0;
  }

  if (a + b <= 0) {
    cout << -1 << endl;
  }
  else {
    cout << (k + b - 1) / (a + b) * 2 + 1 << endl;
  }
  return 0;
}