#include <iostream>
using namespace std;

int main() {
  // (6 <= i) && (5 <= i && i -1 <= i)

  int n;
  cin >> n;

  int h[21];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int ans = 1;
  for (int i = 1; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (h[j] > h[i]) {
        ok = false;
      }
    }
    if (ok) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}