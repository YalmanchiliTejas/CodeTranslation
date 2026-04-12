#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  int max_size = max(x, y);

  int ans = 1e9+1;
  for (int i = 0; i < max_size*2; i++) {
    ans = min(ans, 2*c*i + max(x-i, 0)*a + max(y-i, 0)*b);
  }
  cout << ans << endl;
  return 0;
}