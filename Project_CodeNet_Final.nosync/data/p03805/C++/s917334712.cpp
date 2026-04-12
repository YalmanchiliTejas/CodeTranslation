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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int N, M, a, b, C = 0;

std::vector<std::vector<int>> G;

bool visit[11];


void dfs(int i, int c)
{
  if (c == N) {
    C ++;
  }
  else {
    for (const auto& k : G[i])
      if (! visit[k]) {
        visit[k] = true;

        dfs(k, c + 1);
        
        visit[k] = false;
      }
  }
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);

  std::cin >> N >> M;

  G.resize(N);

  for (int i = 0; i < M; i ++) {
    std::cin >> a >> b;

    a --;
    b --;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  visit[0] = true;

  dfs(0, 1);

  std::cout << C << std::endl;

  return 0;
}
