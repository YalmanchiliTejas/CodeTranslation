#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll
using VI = vector<int>;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define PB push_back

template <typename T> bool IN(T a, T b, T x) { return a<=x&&x<b; }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool board[305][305], used[305][305];
int h, w;
void dfs(int y, int x) {
  used[y][x] = true;
  REP(k, 4) {
    int nx = x + dx[k], ny = y + dy[k];
    if(IN(0LL, w, nx) && IN(0LL, h, ny) && !used[ny][nx] && !board[ny][nx]) {
      dfs(ny, nx);
    }
  }
}

signed main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  while(true) {
    int n;
    cin >> n;
    if(!n) break;
    VI sx(n), sy(n), gx(n), gy(n);
    VI vx, vy;
    REP(i, n) {
      cin >> sx[i] >> sy[i] >> gx[i] >> gy[i];
      sx[i] *= 2, sy[i] *= 2, gx[i] *= 2, gy[i] *= 2;
      vx.PB(sx[i]); vx.PB(sx[i]-1); vx.PB(sx[i]+1);
      vy.PB(sy[i]); vy.PB(sy[i]-1); vy.PB(sy[i]+1);
      vx.PB(gx[i]); vx.PB(gx[i]-1); vx.PB(gx[i]+1);
      vy.PB(gy[i]); vy.PB(gy[i]-1); vy.PB(gy[i]+1);
    }
    vx.PB(-1); vy.PB(-1);
    sort(ALL(vx)); vx.erase(unique(ALL(vx)), vx.end());
    sort(ALL(vy)); vy.erase(unique(ALL(vy)), vy.end());
    memset(board, false, sizeof(board));
    REP(i, n) {
      sx[i] = lower_bound(ALL(vx), sx[i]) - vx.begin();
      sy[i] = lower_bound(ALL(vy), sy[i]) - vy.begin();
      gx[i] = lower_bound(ALL(vx), gx[i]) - vx.begin();
      gy[i] = lower_bound(ALL(vy), gy[i]) - vy.begin();
      FOR(j, sx[i], gx[i]+1) board[sy[i]][j] = board[gy[i]][j] = true;
      FOR(j, gy[i], sy[i]+1) board[j][sx[i]] = board[j][gx[i]] = true;
    }

    h = vy.size(), w = vx.size();

    memset(used, false, sizeof(used));
    int cnt = 0;
    REP(i, h) REP(j, w) {
      if(used[i][j] || board[i][j]) continue;
      dfs(i, j);
      cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}

