#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Town {
  int x;
  int y;
  int idx;
};
struct Entry {
  int cost;
  int idx;
};
const int INF = INT_MAX - 1;
using Visited = bitset<100100>;
int main() {
  int N;
  cin >> N;
  vector<Town> towns(N);
  for(int i = 0; i < N; ++i) {
    cin >> towns[i].x >> towns[i].y;
    towns[i].idx = i;
  }
  vector<vector<Entry>> edges(N);
  sort(towns.begin(), towns.end(), [](const auto& a, const auto& b) { return a.x < b.x; });
  for(int i = 0; i < N - 1; ++i) {
    auto& c = towns[i];
    auto& n = towns[i + 1];
    edges[c.idx].push_back({abs(c.x - n.x), n.idx});
    edges[n.idx].push_back({abs(c.x - n.x), c.idx});
  }
  sort(towns.begin(), towns.end(), [](const auto& a, const auto& b) { return a.y < b.y; });
  for(int i = 0; i < N - 1; ++i) {
    auto& c = towns[i];
    auto& n = towns[i + 1];
    edges[c.idx].push_back({abs(c.y - n.y), n.idx});
    edges[n.idx].push_back({abs(c.y - n.y), c.idx});
  }
  auto compare = [](const auto& a, const auto& b) { return a.cost > b.cost; };
  priority_queue<Entry, vector<Entry>, decltype(compare)> qs(compare);
  qs.push({0, 0});
  long long ans = 0;
  Visited visited;
  while(!qs.empty()) {
    auto q = qs.top();
    qs.pop();
    if(visited.test(q.idx)) {
      continue;
    }
    visited.set(q.idx);
    ans += q.cost;
    for(auto n : edges[q.idx]) {
      qs.push(n);
    }
  }
  cout << ans << endl;
  return 0;
}