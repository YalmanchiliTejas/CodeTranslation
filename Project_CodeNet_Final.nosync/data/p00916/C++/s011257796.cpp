#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ULLI;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int N;
int Y;
int X;
int ls[114];
int rs[114];
int ts[114];
int bs[114];
ULLI field[1145][1419];
bool used[1145][1419];
vector<int> xs;
vector<int> ys;

bool WithinRange(int y, int x) {
  if (y < 0 || Y <= y) return false;
  if (x < 0 || X <= x) return false;
  return true;
}

void dfs(int y, int x) {
  used[y][x] = true;

  for (int i=0; i<4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (!WithinRange(ny, nx)) continue;
    if (used[ny][nx]) continue;
    if (field[y][x] != field[ny][nx]) continue;
    dfs(ny, nx);
  }
}

int main() {
  while (1) {
    scanf("%d", &N);
    if (N == 0) return 0;

    for (int i=0; i<N ; i++) {
      scanf("%d%d%d%d", &ls[i], &ts[i], &rs[i], &bs[i]);
      for (int j=-1; j<=1; j++) {
        xs.emplace_back(ls[i]+j);
        xs.emplace_back(rs[i]+j);
        ys.emplace_back(ts[i]+j);
        ys.emplace_back(bs[i]+j);
      }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
  
    for (int i=0; i<N; i++) {
      ls[i] = lower_bound(xs.begin(), xs.end(), ls[i]) - xs.begin();
      rs[i] = lower_bound(xs.begin(), xs.end(), rs[i]) - xs.begin();
      ts[i] = lower_bound(ys.begin(), ys.end(), ts[i]) - ys.begin();
      bs[i] = lower_bound(ys.begin(), ys.end(), bs[i]) - ys.begin();
    }

    Y = ys.size()+1;
    X = xs.size()+1;
    xs.clear();
    ys.clear();

    fill(field[0], field[Y], 0);
    for (int i=0; i<N; i++) {
      for (int j=bs[i]; j<ts[i]; j++) {
        for (int k=ls[i]; k<rs[i]; k++) {
          field[j][k] |= ULLI(1) << ULLI(i);
        }
      }
    }
  
    fill(used[0], used[Y], false);

    int ans = 0;
    for (int i=0; i<Y; i++) {
      for (int j=0; j<X; j++) {
        if (!used[i][j]) {
          ans++;
          dfs(i, j);
        }
      }
    }
  
    printf("%d\n", ans);
  }
}

