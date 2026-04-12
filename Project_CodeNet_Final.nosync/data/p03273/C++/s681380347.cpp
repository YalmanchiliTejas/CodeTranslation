#include <bits/stdc++.h>
#define FOR(I,X,Y) for(int (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(int (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define INF 1000000007
#define LINF 1000000000000000007
typedef long long ll;
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  char c[H][W];
  bool h[H],w[W];
  FOR(i,0,H)h[i] = 1;
  FOR(j,0,W)w[j] = 1;
  FOR(i,0,H)FOR(j,0,W)cin >> c[i][j];
  FOR(i,0,H){
    bool flag = 1;
    FOR(j,0,W)if(c[i][j] == '#')flag = 0;
    if(flag)h[i] = 0;
  }
  FOR(j,0,W){
    bool flag = 1;
    FOR(i,0,H)if(c[i][j] == '#')flag = 0;
    if(flag)w[j] = 0;
  }
  FOR(i,0,H){
    FOR(j,0,W)if(h[i]&&w[j])cout << c[i][j];
    if(h[i])cout << endl;
  }
}
