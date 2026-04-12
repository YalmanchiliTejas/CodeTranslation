#include<cstdio>
#include<iostream>
#include<cassert>
#include<climits>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

#define MAX 51
int N,M;
string c[MAX];
bool visited[MAX][MAX][4];
bool path[MAX][MAX][4];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

inline bool isValid(int x,int y) { return 0 <= x && x < M && 0 <= y && y < N; }

inline bool check(int x,int y) { rep(i,4) if( path[y][x][i] ) return true; return false; }

struct Point { int x,y; };

void normalize() {
  deque<Point> deq;
  rep(i,N) rep(j,M) {
    int cnt = 0;
    int dir = -1;
    rep(k,4) {
      int nx = j + dx[k], ny = i + dy[k];
      if( !isValid(nx,ny) ) continue;
      if( c[ny][nx] == '#' ) continue;
      ++cnt;
      dir = k;
    }
    if( cnt == 1 ) {
      c[i][j] = '#';
      deq.push_back((Point){j+dx[dir],i+dy[dir]});
    }
  }
  while( !deq.empty() ) {
    Point p = deq.front(); deq.pop_front();
    int cnt = 0;
    int dir = -1;
    rep(i,4) {
      int nx = p.x + dx[i], ny = p.y + dy[i];
      if( !isValid(nx,ny) ) continue;
      if( c[ny][nx] == '#' ) continue;
      ++cnt;
      dir = i;
    }
    if( cnt == 1 ) {
      c[p.y][p.x] = '#';
      deq.push_back((Point){p.x+dx[dir],p.y+dy[dir]});
    }
  }
}

bool dfs(int x,int y,int dir) {
  if( x == 1 && y == 0 ) {
    if( !check(M-1,0) || !check(0,N-1) || !check(M-1,N-1) ) return false;
    return true;
  }
  rep(i,4) {
    int xdir = ( dir + i ) % 4;
    int nx = x + dx[xdir], ny = y + dy[xdir], ndir = xdir;
    if( !isValid(nx,ny) ) {
      nx = x, ny = y;
      ( ndir += 1 ) %= 4;
    } else {
      if( c[ny][nx] == '#' ) {
	( ndir += 1 ) %= 4;
	nx = x, ny = y;
      } else {
	int lx = nx + dx[(ndir+3)%4], ly = ny + dy[(ndir+3)%4];
	if( isValid(lx,ly) && c[ly][lx] != '#' ) ( ndir += 3 ) %= 4;
      }
    }
    if( !( x == nx && y == ny ) && check(nx,ny) ) continue;
    if( visited[ny][nx][ndir] ) continue;
    visited[ny][nx][ndir] = true;
    path[ny][nx][ndir] = true;
    //return dfs(nx,ny,ndir);
    if( dfs(nx,ny,ndir) ) return true;
    path[ny][nx][ndir] = false;
  }  
  return false;
}

bool compute() {
  //normalize();

  memset(visited, false, sizeof visited);
  memset(path, false, sizeof path);
  int x=0,y=0;
  int dir = 0;
  visited[0][0][0] = true;
  path[0][0][0] = true;
  return dfs(0,0,0);
}

int main() {
  while( cin >> N >> M, N|M ) {
    rep(i,N) cin >> c[i];
    puts(compute()?"YES":"NO");
  }
  return 0;
}