#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  c = 2 * c;
  int ans = 1e9;
  for (int i = 0; i <= max(x, y); ++i) {
    int cnt1 = max(0, x - i);
    int cnt2 = max(0, y - i);
    ans = min(ans, a * cnt1 + b * cnt2 + c * i);
  }
  cout << ans << endl;
  return 0;
}