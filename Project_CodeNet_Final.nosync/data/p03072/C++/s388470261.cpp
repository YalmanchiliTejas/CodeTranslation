#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  int ans = 0, c = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    if (h[i] >= c) {
      ans++;
      c = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}