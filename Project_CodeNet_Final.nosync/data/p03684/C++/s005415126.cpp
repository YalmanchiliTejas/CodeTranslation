#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define pii pair <int, int>

#define mp make_pair

#define f first
#define s second

#define pb push_back

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int NN = 20;
const int INF = 1e9 + 7;

struct edge{
  int x, y, z;
};

ll ans;
vector <pair <int, pair <int, int > > > g;
int n;
int p[N];
edge a[N];
pair <int, int> x[N], y[N], z[N];

int get (int x) {
  if (p[x] == x) {
    return x;
  }
  return p[x] = get(p[x]);
}

void unite (int a, int b, int mon) {
  int x = get(a);
  int y = get(b);
  if (x != y) {
    ans += mon * 1LL;
    p[x] = y;
  }
}

int main() {
    #define fn "balls"
    #ifdef witch
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
//        freopen(fn".in", "r", stdin);
//        freopen(fn".out", "w", stdout);
    #endif
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    scanf("%d%d", &a[i].x, &a[i].y);
    x[i].f = a[i].x;
    y[i].f = a[i].y;
    x[i].s = i;
    y[i].s = i;
    z[i].s = i;
  }
  sort (x + 1, x + 1 + n);
  sort (y + 1, y + 1 + n);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= min(n, i + 3); j++) {
      g.pb({x[j].f - x[i].f, {x[i].s, x[j].s}});
    }
    for (int j = i + 1; j <= min(n, i + 3); j++) {
      g.pb({y[j].f - y[i].f, {y[i].s, y[j].s}});
    }
  }
  sort (g.begin(), g.end());
  for (int i = 0; i < g.size(); i++) {
    unite (g[i].s.f, g[i].s.s, g[i].f);
  }
  cout << ans;
  return 0;
}