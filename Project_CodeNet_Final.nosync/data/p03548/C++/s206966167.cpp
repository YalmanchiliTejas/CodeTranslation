#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const int MOD = 1000000007;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  x -= z;
  cout << x / (y + z) << endl;
  return 0;
}
