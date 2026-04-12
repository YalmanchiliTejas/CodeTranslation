#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> m(n);
  for (int i = 0; i < n; i++) cin >> m[i];
  
  int ans = 1;
  
  for (int i = 1; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (m[j] > m[i]) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  }
  
  cout << ans << endl;
}