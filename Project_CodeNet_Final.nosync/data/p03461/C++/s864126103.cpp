#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 105;

int a, b;
int d[MAXN][MAXN];
int f[MAXN][MAXN];
vector < pair< pair<int, int>, int > > ans;

void addEdge(int from, int to, int w) {
  ans.push_back({{from, to}, w});
}

int main() { 

  scanf("%d %d", &a, &b);
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      scanf("%d", &d[i][j]);
    }
  }

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
          int cur = (i + 1) * x + (j + 1) * y;
          f[x][y] = max(f[x][y], d[i][j] - cur);
        }
      }
    }
  }

  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      int dist = 1e9;
      for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
          dist = min(dist, i * x + j * y + f[x][y]);
        }
      }
      if (dist != d[i - 1][j - 1]) {
        puts("Impossible");
        return 0;
      }
    }
  }

  puts("Possible");
  
  int n = 2;
  addEdge(1, 2, 0);
  for (int i = 1; i <= 100; i++) {
    n++;
    addEdge(n - 1, n, -1);
  }

  n++;
  for (int i = 1; i <= 100; i++) {
    n++;
    addEdge(n - 1, n, -2);
  }
  n++;
  addEdge(n - 1, n, 0);

  for (int x = 0; x <= 100; x++) {
    for (int y = 0; y <= 100; y++) {
      addEdge(2 + x, n - 1 - y, f[x][y]);
    }
  }

  printf("%d %d\n", n, sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d ", ans[i].first.first, ans[i].first.second);
    if (ans[i].second >= 0) {
      printf("%d\n", ans[i].second);
    } else if (ans[i].second == -1) {
      printf("X\n");
    } else {
      printf("Y\n");
    }
  }
  printf("%d %d\n", 1, n);

  return 0;
}
