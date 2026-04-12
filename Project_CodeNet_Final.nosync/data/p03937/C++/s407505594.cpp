#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> MAP(H);
  set<pair<ll, ll>> check_set;
  for (int i = 0; i < H; i++) {
    cin >> MAP[i];
    for (int j = 0; j < W; j++) {
      if (MAP[i][j] == '#') check_set.insert({i, j});
    }
  }
  deque<pair<ll, pair<ll, ll>>> q;
  ll max_size = check_set.size();
  q.push_back({1, {0, 0}});
  while (!q.empty()) {
    ll c = q.front().first;
    ll h = q.front().second.first;
    ll w = q.front().second.second;
    q.pop_front();
    if (w == W - 1 && h == H - 1) {
      if (c == max_size) {
        cout << "Possible" << endl;
        return 0;
      }
      continue;
    }
    if (h + 1 < H && MAP[h + 1][w] == '#') {
      q.push_back({c + 1, {h + 1, w}});
    }
    if (w + 1 < W && MAP[h][w + 1] == '#') {
      q.push_back({c + 1, {h, w + 1}});
    }
  }
  cout << "Impossible" << endl;
  return 0;
}