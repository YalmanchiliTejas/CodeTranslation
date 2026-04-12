#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<int(n); i++)
#define all(c) (c).begin(), (c).end()
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int H, W;
char S[8][8];
bool V[8][8];
int DX[4] = {-1, 0, 1, 0};
int DY[4] = {0, -1, 0, 1};

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> H >> W;
  int c = 0;
  rep(y, H) {
    rep(x, W) {
      cin >> S[x][y];
      if (S[x][y] == '#') c++;
    }
  }
  if (c != W+H-1) {
    cout << "Impossible\n";
  }
  else {
    queue<P> q;
    q.push(P(0, 0));
    V[0][0] = true;
    while (!q.empty()) {
      int x = q.front().first,
          y = q.front().second; q.pop();
      rep(k, 4) {
        int nx = x+DX[k], ny = y+DY[k];
        if (nx<0 || nx>=W || ny<0 || ny>=H) continue;
        if (V[nx][ny]) continue;
        q.push(P(nx, ny));
        V[nx][ny] = true;
      }
    }
    if (V[W-1][H-1]) {
      cout << "Possible\n";
    }
    else {
      cout << "Impossible\n";
    }

  }
  return 0;
}
