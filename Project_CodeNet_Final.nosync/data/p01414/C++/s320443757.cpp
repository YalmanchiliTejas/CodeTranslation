#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>

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

int n;
int w[20];
int h[20];
char field[20][20];
int ok[4][4][4][4];
bool visit[1 << 16];

int main() {
  while (scanf("%d", &n) > 0) {
    MEMSET(ok, false);
    REP(i, n) {
      scanf("%d %d", &h[i], &w[i]);
    }
    REP(y, 4) {
      scanf("%s", field[y]);
    }
    FOREQ(x, -3, 3) {
      FOREQ(y, -3, 3) {
        REP(i, n) {
          int lx = max(0, x);
          int rx = max(0, min(3, x + w[i] - 1));
          int ly = max(0, y);
          int ry = max(0, min(3, y + h[i] - 1));
          ok[lx][ly][rx][ry] = 1;
        }
      }
    }

    MEMSET(visit, false);
    int mapto[3] = { 'R', 'G', 'B' };
    visit[0] = true;
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    while (!que.empty()) {
      const int state = que.front().first;
      const int cost = que.front().second;
      que.pop();
      if (state == (1 << 16) - 1) {
        printf("%d\n", cost);
      }
      REP(lx, 4) REP(rx, 4) REP(ly, 4) REP(ry, 4) {
        if (!ok[lx][ly][rx][ry]) { continue; }
        REP(c, 3) {
          int ncost = cost + 1;
          int nstate = state;
          FOREQ(x, lx, rx) FOREQ(y, ly, ry) {
            if (field[y][x] == mapto[c]) {
              nstate |= 1 << (y * 4 + x);
            } else {
              nstate &= ~(1 << (y * 4 + x));
            }
          }
          if (visit[nstate]) { continue; }
          visit[nstate] = true;
          que.push(make_pair(nstate, ncost));
        }
      }
    }
  }
}