#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int r,g,b;
  cin >> r >> g >> b;
  if (((g*10 + b) % 4) == 0) cout << "YES" << endl;
  else cout << "NO" << endl;

return 0;
}