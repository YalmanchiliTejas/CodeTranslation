// implement 15min
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

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

struct Rect {
  int x1, y1, x2, y2;
  Rect() {;}
  Rect(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {;}
};

int n, m;
Rect rect[100];
bool visit[1010][1010];
void PrintVisit() {
  REP(y, m) {
    REP(x, m) {
      putchar(visit[y][x] ? '#' : '.');
    }
    puts("");
  }
}

int main() {
  while (scanf("%d", &n) > 0 && n) {
    {
      // read
      MEMSET(visit, false);
      map<int, int> mapto;
      REP(i, n) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1 *= 2; y1 *= 2; x2 *= 2; y2 *= 2;
        FOREQ(j, -1, 1) {
          mapto[x1 + j] = mapto[x2 + j] = -1;
          mapto[y1 + j] = mapto[y2 + j] = -1;
        }
        rect[i] = Rect(x1, y2, x2, y1);
      }
      int cnt = 2;
      FORIT(it, mapto) { it->second = cnt++; }
      m = cnt;

      // compress & make border
      REP(i, n) {
        rect[i].x1 = mapto[rect[i].x1];
        rect[i].y1 = mapto[rect[i].y1];
        rect[i].x2 = mapto[rect[i].x2];
        rect[i].y2 = mapto[rect[i].y2];
        FOREQ(x, rect[i].x1, rect[i].x2) {
          visit[rect[i].y1][x] = true;
          visit[rect[i].y2][x] = true;
        }
        FOREQ(y, rect[i].y1, rect[i].y2) {
          visit[y][rect[i].x1] = true;
          visit[y][rect[i].x2] = true;
        }
      }
      // PrintVisit();

      // calc region
      int ans = 0;
      REP(sy, m) {
        REP(sx, m) {
          if (visit[sy][sx]) { continue; }
          ans++;
          queue<pair<int, int> > que;
          que.push(make_pair(sx, sy));
          while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            const int dx[4] = { 1, 0, -1, 0 };
            const int dy[4] = { 0, 1, 0, -1 };
            REP(dir, 4) {
              int nx = x + dx[dir];
              int ny = y + dy[dir];
              if (nx < 0 || m < nx || ny < 0 || m < ny || visit[ny][nx]) { continue; }
              visit[ny][nx] = true;
              que.push(make_pair(nx, ny));
            }
          }
        }
      }
      printf("%d\n", ans);
    }
  }
}