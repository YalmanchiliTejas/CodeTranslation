#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int r, g, b;
  cin >> r >> g >> b;
  int res = r * 100 + g * 10 + b;
  if (res % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
