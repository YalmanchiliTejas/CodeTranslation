#include <iostream>
#include <cstdio>
#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

typedef long long ll;

using namespace std;

vector<int> times[50][50];

char g[50][60];
int w,h,m;
int tx[1000];
int ty[1000];

int cont[50][50];
int on[50][50];
int off[50][50];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool move(int x1, int y1, int x2, int y2, int t, int px = -1, int py = -1){
  if(x1 == x2 && y1 == y2){
    if(times[y1][x1].empty() || times[y1][x1].back() != t)
      times[y1][x1].push_back(t);
    return true;
  }

  REP(i,4){
    int xx = x1 + dx[i];
    int yy = y1 + dy[i];

    if(xx <  0) continue;
    if(yy <  0) continue;
    if(xx >= w) continue;
    if(yy >= h) continue;
    if(xx == px && yy == py) continue;
    if(g[yy][xx] == '#') continue;

    if(move(xx, yy, x2, y2, t + 1, x1, y1)){
      if(times[y1][x1].empty() || times[y1][x1].back() != t)
	times[y1][x1].push_back(t);
      return true;
    }
  }

  return false;
}

int main(){
  scanf("%d%d%d", &h, &w, &m);
  REP(i,h) scanf("%s", g[i]);
  REP(i,h) REP(j,w) scanf("%d", &cont[i][j]);
  REP(i,h) REP(j,w) scanf("%d", &on[i][j]);
  REP(i,h) REP(j,w) scanf("%d", &off[i][j]);

  REP(i,m) scanf("%d%d", ty+i, tx+i);

  times[ty[0]][tx[0]].push_back(0);
  REP(i,m - 1){
    move(tx[i], ty[i], tx[i+1], ty[i+1], times[ty[i]][tx[i]].back());
  }

  ll ans = 0;

  REP(i,h) REP(j,w){
    int n = times[i][j].size();
    if(n != 0) ans += on[i][j] + off[i][j];

    REP(k, n - 1){
      int duration = times[i][j][k+1] - times[i][j][k];
      ans += min(duration * cont[i][j], on[i][j] + off[i][j]);
    }
  }

  cout << ans << endl;

  return 0;
}