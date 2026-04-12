#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int x, y, z;
  cin >> x >> y >> z;

  int ans = 0;

  x -= y + 2 * z;
  ans++;

  while (x >= y + z) {
    x -= y + z;
    ans++;
  }

  cout << ans << endl;
  
  return 0;
}