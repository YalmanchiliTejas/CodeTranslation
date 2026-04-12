#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

template<class T> inline bool in_range(T y, T x, T H, T W) { return 0<=y&&y<H&&0<=x&&x<W; }

auto ng() {
  cout << "Impossible\n"; exit(0);
}

int main() {

  int H, W; cin >> H >> W;
  vector<string> A(H);
  rep(i, H) {
    cin >> A[i];
  }

  int y {0}, x {0};
  vector<vector<bool>> vis(H, vector<bool>(W));
  if(A[0][0] == '.') ng();
  vis[0][0] = 1;
  while(y != H-1 || x != W-1) {
    int dir = -1;
    rep(k, 4) {
      const int ny {y + dy[k]}, nx {x + dx[k]};
      if(!in_range(ny, nx, H, W)) continue;
      if(vis[ny][nx]) continue;
      if(A[ny][nx] == '.') continue;
      if(k == 0 || k == 1) ng();
      if(dir < 0) dir = k;
      else ng();
    }
    if(dir < 0) ng();
    y += dy[dir], x += dx[dir];
    vis[y][x] = 1;
  }

  rep(i, H) rep(j, W) if((A[i][j] == '#')^(vis[i][j])) ng();

  cout << "Possible\n";
  
  return 0;
}