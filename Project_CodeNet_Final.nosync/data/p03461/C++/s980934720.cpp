#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

int A, B;
int D[15][15];
int f[105][105];

int main(){

  cin >> A >> B;
  rep(i,A){
    rep(j,B){
      cin >> D[i][j];
    }
  }

  rep(a,101){
    rep(b,101){
      rep(x,A){
        rep(y,B){
          f[a][b] = max(f[a][b], D[x][y] - (x+1)*a - (y+1)*b);
        }
      }
    }
  }

  rep(x,A){
    rep(y,B){
      int mn = 1000000000;
      rep(a,101){
        rep(b,101){
          mn = min(mn, (x+1)*a + f[a][b] + (y+1)*b);
        }
      }
      if(D[x][y] != mn){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  
  cout << "Possible" << endl;
  cout << 202 << " " << 200+101*101 << endl;
  rep(i,100){
    cout << i+1 << " " << i+2 << " X" << endl;
  }
  rep(i,100){
    cout << 102+i << " " << 102+i+1 << " Y" << endl;
  }
  rep(i,101){
    rep(j,101){
      cout << i+1 << " " << 202-j << " " << f[i][j] << endl;
    }
  }
  
  cout << 1 << " " << 202 << endl;
  
  return 0;
}
