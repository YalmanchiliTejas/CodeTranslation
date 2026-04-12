#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAXR = 51;
const int MAXC = 51;
const int INF = 1<<28;
const int di[] = {0,1,0,-1};
const int dj[] = {1,0,-1,0};
int R, C, M;
char G[MAXR][MAXC];
int P[3][MAXR][MAXC];
vector<int> V[MAXR][MAXC];

vector<pair<int,int> > bfs(int r, int c, int gr, int gc) {
  queue<pair<int,int> > que;
  int vis[MAXR][MAXC];
  pair<int,int> path[MAXR][MAXC];
  fill(vis[0],vis[MAXR],INF);
  que.push(make_pair(r,c));
  vis[r][c] = 0;
  path[r][c] = make_pair(-1,-1);
  while(!que.empty()) {
    r = que.front().first;
    c = que.front().second;
    que.pop();
    for(int i = 0; i < 4; ++i) {
      int nr = r + di[i];
      int nc = c + dj[i];
      if(nr < 0 || nr >= R) continue;
      if(nc < 0 || nc >= C) continue;
      if(G[nr][nc] == '#') continue;
      if(vis[nr][nc] != INF) continue;
      vis[nr][nc] = vis[r][c] + 1;
      path[nr][nc] = make_pair(r,c);
      if(nr == gr && nc == gc) {
	vector<pair<int,int> > v;
	pair<int,int> p = make_pair(nr,nc);
	while(p.first != -1) {
	  v.push_back(p);
	  p = path[p.first][p.second];
	}
	reverse(v.begin(), v.end());
	return v;
      }
      que.push(make_pair(nr,nc));
    }
  }
  return vector<pair<int,int> >();
}

int main() {
  while(cin >> R >> C >> M) {
    for(int i = 0; i < R; ++i) {
      for(int j = 0; j < C; ++j) {
	cin >> G[i][j];
      }
    }
    for(int k = 0; k < 3; ++k) {
      for(int i = 0; i < R; ++i) {
	for(int j = 0; j < C; ++j) {
	  cin >> P[k][i][j];
	}
      }
    }

    fill(V[0],V[MAXR],vector<int>());
    int r, c, t;
    r = c = -1;
    t = 0;
    while(M--) {
      int nr, nc;
      cin >> nr >> nc;
      if(r == -1) {
	V[nr][nc].push_back(0);
      } else {
	vector<pair<int,int> > v = bfs(r,c,nr,nc);
	/*
	for(int i = 0; i < v.size(); ++i) {
	  cout << v[i].first << ", " << v[i].second << endl;
	}
	cout << endl;
	*/
	for(int i = 1; i < v.size(); ++i) {
	  V[v[i].first][v[i].second].push_back(++t);
	}
      }
      r = nr;
      c = nc;
    }
    int res = 0;
    for(int i = 0; i < R; ++i) {
      for(int j = 0; j < C; ++j) {
	vector<int> &v = V[i][j];
	if(v.size() == 0) continue;
	res += P[1][i][j] + P[2][i][j];
	for(int k = 1; k < v.size(); ++k) {
	  int d = v[k] - v[k-1];
	  res += min(d*P[0][i][j], P[1][i][j]+P[2][i][j]);
	}
      }
    }
    cout << res << endl;
  }
  return 0;
}