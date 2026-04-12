#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int h;
  cin >> n;
  int m = -1;
  int res = 0;
  for (int i = 0; i < n; i++) {
    cin >> h;
    if (m <= h) {
      res++;
    }
    m = max(m, h);
  }
  cout << res << endl;
}
