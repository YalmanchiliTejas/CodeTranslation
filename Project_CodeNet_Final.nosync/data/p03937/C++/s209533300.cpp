#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int H, W;
  while (cin >> H >> W) {
    vector<string> a(H);
    for (int i = 0; i < H; i++) cin >> a[i];
    bool reacheable = true;
    int y = 0, x = 0;
    while (y != H - 1 || x != W - 1) {
      if (x + 1 < W && a[y][x + 1] == '#') {
        ++x;
      } else if (y + 1 < H && a[y + 1][x] == '#') {
        ++y;
      } else {
        reacheable = false;
        break;
      }
    }
    int cnt = 0;
    for (auto& line : a) cnt += count(line.begin(), line.end(), '#');
    bool res = reacheable && cnt == H + W - 1;
    cout << (res ? "Possible" : "Impossible") << endl;
  }
  return 0;
}
