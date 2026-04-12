#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

constexpr size_t di[]={size_t(-1), 0, 1, 0};
constexpr size_t dj[]={0, size_t(-1), 0, 1};

void dfs(std::vector<std::vector<intmax_t>>& g, size_t i, size_t j) {
  assert(g[i][j] != -1);
  intmax_t c = g[i][j];
  g[i][j] = -1;

  size_t m = g.size();
  for (size_t k=0; k<4; ++k) {
    size_t ni = i+di[k];
    size_t nj = j+dj[k];
    if (!(ni < m && nj < m)) continue;
    if (g[ni][nj] != c) continue;
    dfs(g, ni, nj);
  }
}

int comps(std::vector<std::vector<intmax_t>> g) {
  size_t m = g.size();
  int res = 0;
  for (size_t i=0; i<m; ++i)
    for (size_t j=0; j<m; ++j)
      if (g[i][j] > -1) {
        dfs(g, i, j);
        ++res;
      }

  return res;
}

int testcase_ends() {
  size_t n;
  scanf("%zu", &n);

  if (n == 0) return 1;

  std::vector<int> L(n), T(n), R(n), B(n);
  std::map<int, int> X, Y;
  for (size_t i=0; i<n; ++i) {
    scanf("%d %d %d %d", &L[i], &T[i], &R[i], &B[i]);
    X.emplace(L[i], 0);
    X.emplace(R[i], 0);
    Y.emplace(B[i], 0);
    Y.emplace(T[i], 0);
  }

  {
    int x = 0;
    for (auto& p: X) p.second = ++x;
  }
  {
    int y = 0;
    for (auto& p: Y) p.second = ++y;
  }

  size_t m = 2*(n+1);
  std::vector<std::vector<intmax_t>> g(m, std::vector<intmax_t>(m));
  for (size_t i=0; i<n; ++i) {
    int l = X[L[i]];
    int t = Y[T[i]];
    int r = X[R[i]];
    int b = Y[B[i]];
    intmax_t mask = intmax_t(1) << i;

    for (int x=l; x<r; ++x)
      for (int y=b; y<t; ++y)
        g[x][y] |= mask;
  }

  printf("%d\n", comps(g));
  return 0;
}

int main() {
  while (!testcase_ends()) {}
}

