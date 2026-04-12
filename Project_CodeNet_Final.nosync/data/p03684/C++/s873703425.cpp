#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int N;

  std::cin >> N;

  std::vector<long long> x(N), y(N);

  for (int i = 0; i < N; i ++)
    std::cin >> x[i] >> y[i];

  std::vector<std::vector<std::pair<int, int>>> G(N);

  std::vector<int> indices(N);

  std::iota(ALL(indices), 0);

  std::sort(ALL(indices), [&x](int a, int b) {
      return x[a] < x[b];
    });

  for (int i = 0; i < N; i ++) {
    int index = indices[i];
    
    if (i > 0) {
      int index2 = indices[i - 1];
      
      G[index].emplace_back(index2, x[index] - x[index2]);
    }
    
    if (i < N - 1) {
      int index2 = indices[i + 1];
      
      G[index].emplace_back(index2, x[index2] - x[index]);
    }
  }

  std::sort(ALL(indices), [&y](int a, int b) {
      return y[a] < y[b];
    });

  for (int i = 0; i < N; i ++) {
    int index = indices[i];
    
    if (i > 0) {
      int index2 = indices[i - 1];
      
      G[index].emplace_back(index2, y[index] - y[index2]);
    }
    
    if (i < N - 1) {
      int index2 = indices[i + 1];
      
      G[index].emplace_back(index2, y[index2] - y[index]);
    }
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

  std::vector<bool> visit(N);

  pq.emplace(-1, 0);

  long long l = 0;

  while (! pq.empty()) {
    int d, i, k;

    std::tie(d, i) = pq.top(); pq.pop();

    if (visit[i])
      continue;

    visit[i] = true;

    l += std::max(d, 0);

    std::cerr << "i=" << i << " d=" << d << " l=" << l << std::endl;

    for (const auto& e : G[i]) {
      std::tie(k, d) = e;

      if (! visit[k])
        pq.emplace(d, k);
    }
  }

  std::cout << l << std::endl;

  return 0;
}
