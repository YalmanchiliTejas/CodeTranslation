#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int H, W;
  char a[101][101];
  bool wh_row[101];
  bool wh_col[101];
  cin >> H >> W;

  rep(i,H) {
    rep(j,W) {
      cin >> a[j][i];
    }
  }

  rep(i,H) wh_row[i]=true;
  rep(i,W) wh_col[i]=true;

  rep(i,H) {
    rep(j,W) {
      if(a[j][i]=='#') {
        wh_row[i]=false;
        break;
      }
    }
  }

  rep(j,W) {
    rep(i,H) {
      if(a[j][i]=='#') {
        wh_col[j]=false;
        break;
      }
    }
  }
  
  rep(i,H) {
    if(!wh_row[i]) {
      rep(j,W) {
	if(!wh_col[j]) cout << a[j][i];
      }
      cout << endl;
    }
  }

}
