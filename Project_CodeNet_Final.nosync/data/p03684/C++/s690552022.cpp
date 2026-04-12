#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <queue>
#include <deque>
#include <functional>

template <class T>
using lp_queue=std::priority_queue<T, std::deque<T>, std::greater<T>>;

struct Edge {
  size_t src, dst;
  intmax_t cost;
  Edge(size_t src, size_t dst, intmax_t cost):
    src(src), dst(dst), cost(cost) {}
};

intmax_t mst(const std::vector<std::vector<Edge>> &g) {
  std::vector<bool> visited(g.size());
  lp_queue<std::pair<intmax_t, size_t>> q;
  q.emplace(0, 0);
  intmax_t res=0;
  while (!q.empty()) {
    std::pair<intmax_t, size_t> p=q.top();
    q.pop();
    intmax_t w=p.first;
    size_t v=p.second;
    if (visited[v]) continue;
    visited[v] = true;
    res += w;
    for (const Edge &e: g[v]) {
      q.emplace(e.cost, e.dst);
    }
  }
  return res;
}

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::pair<intmax_t, size_t>> x(N), y(N);
  for (size_t i=0; i<N; ++i) {
    scanf("%jd %jd", &x[i].first, &y[i].first);
    x[i].second = y[i].second = i;
  }

  std::sort(x.begin(), x.end());
  std::sort(y.begin(), y.end());

  std::vector<std::vector<Edge>> g(N);
  for (size_t i=1; i<N; ++i) {
    g[x[i].second].emplace_back(x[i].second, x[i-1].second, 
				x[i].first-x[i-1].first);
    g[x[i-1].second].emplace_back(x[i-1].second, x[i].second, 
				  x[i].first-x[i-1].first);
    g[y[i].second].emplace_back(y[i].second, y[i-1].second, 
				y[i].first-y[i-1].first);
    g[y[i-1].second].emplace_back(y[i-1].second, y[i].second, 
				  y[i].first-y[i-1].first);
  }

  printf("%jd\n", mst(g));
}
