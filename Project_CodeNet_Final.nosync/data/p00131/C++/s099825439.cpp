#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<30;

bool ans[10][10];
bool ba[10][10];
int dx[] = {-1,0,0,0,1};
int dy[] = {0, -1,0, 1, 0};

bool judge(int x, int y) {
  int res = ba[x][y];
  REP(k,5) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (xx < 0 || xx >= 10 || yy < 0 || yy >= 10) continue;
    if (ans[xx][yy]) res++;
  }
  return res % 2;
}

int main() {
  int n;
  cin >> n;
  while(n--) {
    REP(y,10)
      REP(x,10)
      cin >> ba[x][y];
    
    for (int i=0; i<(1<<10); ++i) {
      memset(ans, 0, sizeof(ans));
      REP(j,10)
        if ((i>>j)&1)
          ans[j][0] = 1;
      for(int y=1; y<10; ++y) {
        REP(x,10) {
          if (judge(x,y-1))
            ans[x][y] = 1;
        }
      }
      bool f = 1;
      REP(i,10)
        if (judge(i, 9)) f = 0;
      if (f) 
        break;
    }
    REP(y,10) {
      REP(x,10) {
        if (x) cout << " ";
        cout << ans[x][y];
      }
      cout << endl;
    }
  }
}