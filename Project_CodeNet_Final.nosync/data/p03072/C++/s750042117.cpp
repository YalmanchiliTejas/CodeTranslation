#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int max_h = -1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (h[i] >= max_h) {
      max_h = h[i];
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
