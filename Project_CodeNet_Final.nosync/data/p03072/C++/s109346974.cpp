#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
constexpr long long int INF = std::numeric_limits<long long int>::max();
#define int long long int

void solve() {
  int N;
  cin >> N;

  int ans = 0;
  int hmax = 0;

  while (N--) {
    int h;
    cin >> h;
    if (hmax <= h) {
      ans++;
      hmax = h;
    }
  }

  cout << ans << endl;
}

signed main() {
  solve();
  return 0;
}
