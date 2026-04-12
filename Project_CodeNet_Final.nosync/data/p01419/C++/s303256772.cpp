#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

int h, w, m;
char field[100][100];
ll cont[100][100];
ll on[100][100];
ll off[100][100];
int prev[100][100];
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

void Input(ll mat[100][100]) {
  REP(y, h) {
    REP(x, w) {
      scanf("%lld", &mat[y][x]);
    }
  }
}

bool dfs(int x, int y, int px, int py, int gx, int gy, stack<pair<int, int> > &st) {
  if (x == gx && y == gy) { return true; }
  REP(dir, 4) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx == px && ny == py) { continue; }
    if (nx < 0 || nx >= w || ny < 0 || ny >= h) { continue; }
    if (field[ny][nx] == '#') { continue; }
    if (dfs(nx, ny, x, y, gx, gy, st)) {
      st.push(make_pair(nx, ny));
      return true;
    }
  }
  return false;
}

ll In(int x, int y, int &t) {
  ll ret = 1LL << 60;;
  ret = on[y][x] + off[y][x];
  if (prev[y][x] != -1) {
    ret = min(ret, (t - prev[y][x]) * cont[y][x]);
  }
  prev[y][x] = t;
  t++;
  return ret;
}

int main() {
  while (scanf("%d %d %d", &h, &w, &m) > 0) {
    MEMSET(prev, -1);
    REP(y, h) {
      scanf("%s", field[y]);
    }
    Input(cont);
    Input(on);
    Input(off);
    int px, py;
    scanf("%d %d", &py, &px);
    int t = 0;
    ll ans = 0;
    ans += In(px, py, t);
    REP(iter, m - 1) {
      int nx, ny;
      scanf("%d %d", &ny, &nx);
      stack<pair<int, int> > st;
      dfs(px, py, px, py, nx, ny, st);
      while (!st.empty()) {
        int x = st.top().first;
        int y = st.top().second;
        st.pop();
        ans += In(x, y, t);
      }
      px = nx;
      py = ny;
    }
    printf("%lld\n", ans);
  }
}