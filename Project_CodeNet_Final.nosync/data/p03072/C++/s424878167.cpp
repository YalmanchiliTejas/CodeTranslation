#include <bits/stdc++.h>

using namespace std;
int main() {
  int n;
  cin >> n;
  int h[n] = {0};
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int maxH = 0;
  int result = 0;
  for (int i = 0; i < n; i++) {
    maxH = max(maxH, h[i]);
    if (h[i] >= maxH) ++result;
  }
  cout << result << endl;
  return 0;
}