#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX

const double EPS = 1e-14;
const double PI  = acos(-1.0);


int main(){
  int h, w;
  cin >> h >> w;

  char a[h + 2][w + 2];
  REP (i, h) {
    REP (j, w) {
      cin >> a[i][j];
    }
  }

  bool z = false;
  while(!z) {
    z = true;
    REP (i, h) {
      bool flag = true;
      REP (j, w) {
        if (a[i][j] == '#') flag = false;
      }
      if (flag) {
        FOR(k, i, h - 1) {
          REP (j, w) {
            a[k][j] = a[k + 1][j];
          }
        }
        z = false;
        h--;
      }
    }
    REP (j, w) {
      bool flag = true;
      REP (i, h) {
        if (a[i][j] == '#') flag = false;
      }
      if (flag) {
        FOR(k, j, w - 1) {
          REP (i, h) {
            a[i][k] = a[i][k + 1];
          }
        }
        z = false;
        w--;
      }
    }
  }

  REP (i, h) {
    REP (j, w) {
      cout << a[i][j];
      if (j == w - 1) cout << endl;
    }
  }

}
