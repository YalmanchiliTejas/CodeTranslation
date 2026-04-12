#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
std::vector<int> g[1 + nmax];
int sz[1 + nmax];
bool verdict = 1;
void dfs(int node, int parent) {
  sz[node] = 1;
  int ned = 0;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node);
      sz[node] += sz[to];
      ned += sz[to] % 2;
    }
  }
  if(1 < ned)
    verdict = 0;
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  if(sz[1] % 2 == 1 || verdict == 0)
    std::cout << "First";
  else
    std::cout << "Second";
  return 0;
}
