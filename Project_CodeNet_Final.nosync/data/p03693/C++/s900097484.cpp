#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b, rgb;
  cin >> r >> g >> b;
  rgb = 100 * r + 10 * g + b;
  string ans = (rgb % 4) ? "NO" : "YES";
  cout << ans << endl;
}
