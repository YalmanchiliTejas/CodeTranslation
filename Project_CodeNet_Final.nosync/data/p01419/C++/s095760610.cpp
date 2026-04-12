#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <memory.h>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef pair<int, int> P;
const double EPS = 1e-12;
const int INF = 1 << 29;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
P par[60][60];
char field[60][60];
int oncost[60][60];
int offcost[60][60];
int keepcost[60][60];
int dist[60][60];
int r[2000];
int c[2000];

vector<int> visit[60][60];
int R, C, M;

void bfs(int sr, int sc){
  int r, c;
  queue<P> que;
  que.push(P(sr, sc));
  while(!que.empty()){
    P p = que.front();
    que.pop();
    r = p.first;
    c = p.second;
    rep(i, 4){
      int r2 = r + dy[i];
      int c2 = c + dx[i];
      if(0 <= r2 && r2 < R && 0 <= c2 && c2 < C && dist[r2][c2] == -1 && field[r2][c2] == '.'){
	dist[r2][c2] = dist[r][c] + 1;
	que.push(P(r2, c2));
	par[r2][c2] = p;
      }
    }
  }
}

int main(){
  cin >> R >> C >> M;
  rep(i, R) rep(j, C) cin >> field[i][j];
  rep(i, R) rep(j, C) cin >> keepcost[i][j];
  rep(i, R) rep(j, C) cin >> oncost[i][j];
  rep(i, R) rep(j, C) cin >> offcost[i][j];
  rep(i,M){
    cin >> r[i] >> c[i];
  }
  int t = 0;
  int res = 0;
  rep(i, M - 1){
    memset(dist, -1, sizeof(dist));
    memset(par, -1, sizeof(par));
    dist[r[i]][c[i]] = 0;
    bfs(r[i], c[i]);
    for(P p = P(r[i+1], c[i+1]); p.first != -1; p = par[p.first][p.second]){
      visit[p.first][p.second].push_back(t + dist[p.first][p.second]);
    }
    t += dist[r[i+1]][c[i+1]];
  }
  rep(i, R)rep(j, C){

    if(!visit[i][j].empty()){
      sort(visit[i][j].begin(), visit[i][j].end());
      res += oncost[i][j] + offcost[i][j];
      rep(k, (int)visit[i][j].size() - 1){
	int d = visit[i][j][k+1] - visit[i][j][k];
	int add = min(d * keepcost[i][j], oncost[i][j] + offcost[i][j]); 
	res += add;
      }
    }
  }
  cout << res << endl;
  return 0;
}