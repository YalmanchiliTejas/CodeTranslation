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

struct State {
  int cost;
  int number;
  int x;
  int y;
  State() {;}
  State(int cost, int number, int x, int y) : cost(cost), number(number), x(x), y(y) {;}
  bool operator<(const State &rhs) const {
    return cost > rhs.cost;
  }
};

int h, w;
int gx, gy;
int maxnumber;
int field[110][110];
bool visit[2510][2510];
//int dist[2510][2510];
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
  while (scanf("%d %d", &w, &h), w|h) {
    MEMSET(field, 0);
    MEMSET(visit, false);
    //MEMSET(dist, 0x0f);
    maxnumber = 0;
    int sy, sx;
    REP(y, h) {
      REP(x, w) {
        char str[100];
        scanf("%s", str);
        if (str[0] == 'S') {
          sx = x; sy = y;
        } else if (str[0] == 'G') {
          gx = x; gy = y;
        } else if (str[0] != '.') {
          int num = atoi(str);
          maxnumber = max(maxnumber, num);
          field[y][x] = num;
        }
      }
    }
    field[gy][gx] = maxnumber + 1;

    queue<State> que;
    que.push(State(0, 1, sx, sy));
    while (!que.empty()) {
      State state = que.front();
      que.pop();
      if (visit[state.number][state.y * w + state.x]) { continue; }
      visit[state.number][state.y * w + state.x] = true;
      if (state.number >= maxnumber + 1 && state.y == gy && state.x == gx) {
        printf("%d\n", state.cost);
        goto end;
      }
      REP(dir, 4) {
        int nx = state.x + dx[dir];
        int ny = state.y + dy[dir];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h) { continue; }
        //if (field[ny][nx] > state.number) { continue; }
        int nnumber = state.number;
        int ncost = state.cost + 1;
        if (field[ny][nx] == nnumber) {
          nnumber++;
        }
        que.push(State(ncost, nnumber, nx, ny));
      }
    }
end:;
  }
}