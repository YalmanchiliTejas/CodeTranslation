#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int ans = (x - z) / (y + z);
  cout << ans << endl;
  return 0;
}
