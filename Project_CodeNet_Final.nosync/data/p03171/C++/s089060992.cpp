#include <algorithm>
#include <array>
#include <bitset>
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


int N, a[3333];

long long memo[3333][3333][2];


long long dfs(int i, int j, int k)
{
  if (memo[i][j][k] < INF)
    return memo[i][j][k];

  if (i == j)
    return memo[i][j][k] = k == 0 ? a[i] : - a[i];

  if (k == 0) {
    return memo[i][j][k] = std::max(dfs(i + 1, j,     1 - k) + a[i],
                                    dfs(i,     j - 1, 1 - k) + a[j]);
  }
  else {
    return memo[i][j][k] = std::min(dfs(i + 1, j,     1 - k) - a[i],
                                    dfs(i,     j - 1, 1 - k) - a[j]);
  }

  assert(false);
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);
  std::cerr << std::fixed << std::setprecision(6);

  std::cin >> N;

  for (int i = 0; i < N; i ++)
    std::cin >> a[i];

  for (int i = 0; i < 3333; i ++)
    for (int j = 0; j < 3333; j ++)
      for (int k = 0; k < 2; k ++)
        memo[i][j][k] = INF;

  std::cout << dfs(0, N - 1, 0) << std::endl;

  return 0;
}
