#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, H[30];
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
      cin >> H[i];
      bool tmp = 1;
      for (int j = 0; j < i; ++j) {
          if (H[j] > H[i]) tmp = 0;
      }
      ans += tmp;
  }

  cout << ans << endl;
  return 0;
}