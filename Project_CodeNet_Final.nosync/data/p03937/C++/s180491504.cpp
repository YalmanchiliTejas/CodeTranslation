#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char a[H][W];
  char b[H][W];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++) cin >> a[i][j];
  }
  int flag=0;
  for(int i=0; i<H-1; i++){
    for(int j=0; j<W-1; j++){
      if(a[i][j]=='.' && a[i+1][j]=='#' && a[i][j+1]=='#' && a[i+1][i+1]=='#') flag++;
      else if(a[i][j]=='#' && a[i+1][j]=='#' && a[i][j+1]=='#' && a[i+1][j+1]=='#') flag++;
      else if(a[i][j]=='#' && a[i+1][j]=='#' && a[i][j+1]=='#' && a[i+1][j+1]=='.') flag++;
    }
  }
  if(flag>0) cout << "Impossible" << endl;
  else cout << "Possible" << endl;
}
