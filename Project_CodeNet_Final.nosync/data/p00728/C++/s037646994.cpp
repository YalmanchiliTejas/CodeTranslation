#include <iostream>
using namespace std;

int main() {
  int n;
  while (1) {
    cin >> n;
    if (n == 0) break;

    int sum = 0, minv = 100000, maxv = -1;
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      if (s < minv) minv = s;
      if (s > maxv) maxv = s;
      sum += s;
    }
    sum -= minv + maxv;
    int ave = sum / (n - 2);
    
    cout << ave << endl;
  }

  return 0;
}
