#include <bits/stdc++.h>
using namespace std;
int main(void){
  int H, W;
  cin >> H >> W;
  char a[H][W];
  for(int i=0; i<H; i++) for(int j=0; j<W; j++) cin >> a[i][j];
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      bool dis_row = false;
      for(int k=0; k<W; k++) if(a[i][k] == '#') {dis_row = true; break;}
      bool dis_col = false;
      for(int k=0; k<H; k++) if(a[k][j] == '#') {dis_col = true; break;}

      if(dis_row && dis_col) cout << a[i][j];
      if(dis_row && j == W-1) cout << endl;
    }
  }
  return 0;
  
}