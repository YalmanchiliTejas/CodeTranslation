#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 30;

bool g[10][10];
int p[10];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
    g[x][y] = g[y][x] = true;
  }
  for (int i = 0; i < n; ++i) p[i] = i;
  int ret = 0;
  do {
    bool found = false;
    if (p[0] != 0) continue;
    for (int i = 1; i < n; ++i) {
      if (!g[p[i - 1]][p[i]]) {
        found = true;
        break;
      }
    }
    if (!found) ++ret;
  } while (next_permutation(p, p + n));
  printf("%d\n", ret);
  return 0;
}
