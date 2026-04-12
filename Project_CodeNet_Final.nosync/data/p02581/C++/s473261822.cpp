#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<ll, int>;

#define INF 1001001001

int main() {
  int n;
  cin >> n;
  vector< vector<int> > dp(n+1, vector<int>(n+1,-1));
  map<P,int> next;
  P maxidx = {0,0};
  vector<int> maxidx1(n+1), maxidx2(n+1); 
  int x, y, z;

  auto move = [&](P from, P to, bool plus) {
    int fx, fy, tx, ty;
    tie (fx,fy) = from;
    if (dp[fx][fy]==-1) return;
    next[to] = max(next[to],dp[fx][fy]+plus);
  };
  auto update = [&] {
    int x, y;
    for (auto m : next) {
      tie(x,y) = m.first;
      dp[x][y] = m.second;
      if (dp[x][y] > dp[maxidx.first][maxidx.second]) maxidx = {x,y};
      if (dp[x][y] > dp[maxidx1[y]][y]) maxidx1[y] = x;
      if (dp[x][y] > dp[x][maxidx2[x]]) maxidx2[x] = y;
    }
    next.clear();
  };

  cin >> x >> y; x--; y--;
  dp[x][y] = 0;
  move({x,y},{x,y},false);
  update();
  int ans = 0;
  rep(i,n) {
    if (i==n-1) {
      cin >> x; x--;
      y = z = n;
    } else {
      cin >> x >> y >> z;
      x--; y--; z--;
    }
    if (x == y && y == z) {
      ans++;
      update();
      continue;
    }
    if (x == y || x == z || y == z) {
      int p, q;
      if (x == y) p = x, q = z;
      if (x == z) p = x, q = y;
      if (y == z) p = y, q = x;
      rep(j,n) {
        move({j,p},{j,q},true);
        move({p,j},{j,q},true);
      }
    }
    move({x,x},{y,z},true);
    move({y,y},{x,z},true);
    move({z,z},{x,y},true);

    move(maxidx,{x,y},false);
    move(maxidx,{x,z},false);
    move(maxidx,{y,z},false);

    rep(j,n) {
      move({maxidx1[j],j},{j,x},false);
      move({j,maxidx2[j]},{j,x},false);
      move({maxidx1[j],j},{j,y},false);
      move({j,maxidx2[j]},{j,y},false);
      move({maxidx1[j],j},{j,z},false);
      move({j,maxidx2[j]},{j,z},false);
    }
    update();
  }
  ans += dp[maxidx.first][maxidx.second];

  cout << ans << endl;

  return 0;
}