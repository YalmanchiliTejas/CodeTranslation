#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int x = 100 * r + 10 * g + b;
  if(x % 4) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}