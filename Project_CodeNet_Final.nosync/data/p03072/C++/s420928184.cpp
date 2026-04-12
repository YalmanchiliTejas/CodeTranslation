#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, h;
  cin >> n;
  int res = 0, mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> h;
    if (h >= mx) {
      ++res;
      mx = h;
    }
  }
  cout << res << endl;


  return 0;
}

