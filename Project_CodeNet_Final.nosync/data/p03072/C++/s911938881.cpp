#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  int h[n];
  int i;
  for (i = 0; i < n; i++) {
    cin >> h[i];
  }
  int max_h = 0;
  int result = 0;
  for (i = 0; i < n; i++) {
    if (max_h <= h[i]) {
      result ++;
    }
    max_h = max(max_h, h[i]);

  }
  cout << result << endl;
  return 0;
}
