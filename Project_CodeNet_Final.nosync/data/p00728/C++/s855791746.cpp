#include <iostream>
using namespace std;

int main() {
  while (true) {
    int n; cin >> n;
    if (!n) break;
    int min = 1000, max = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      int s; cin >> s;
      sum += s;
      if (s < min) min = s;
      if (s > max) max = s;
    }
    cout << (sum - min - max) / (n - 2) << endl;
  }
  return 0;
}
