#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int sum = 0, minv = 1000, maxv = 0;
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      maxv = max(maxv, s);
      minv = min(minv, s);
      sum += s;
    }
    sum -= maxv + minv;
    cout << sum / (n - 2) << endl;
  }
  return 0;
}