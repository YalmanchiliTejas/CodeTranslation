#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 8;

char v[1 + nmax][1 + nmax];

int main() {
  int n, m;
  std::cin >> n >> m;
  int result = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++) {
      std::cin >> v[i][j];
      result += (v[i][j] == '#');
    }
  if(result == n + m - 1)
    std::cout << "Possible";
  else
    std::cout << "Impossible";
  return 0;
}
