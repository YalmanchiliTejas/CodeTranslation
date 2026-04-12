#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  bool nul;
  cin >> H >> W;
  char a[H][W];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++) cin >> a[i][j];
  }
  for(int i=0; i<H; i++){
    nul = true;
    for(int j=0; j<W; j++){
      if(a[i][j]=='#') nul = false;
    }
    if(nul) for(int j=0; j<W; j++) a[i][j] = '0';
  }
  for(int i=0; i<W; i++){
    nul = true;
    for(int j=0; j<H; j++){
      if(a[j][i]=='#') nul = false;
    }
    if(nul) for(int j=0; j<H; j++) a[j][i] = '0';
  }
  for(int i=0; i<H; i++){
    nul = true;
    for(int j=0; j<W; j++) if(a[i][j]!='0'){
      cout << a[i][j];
      nul = false;
    }
    if(!nul) cout << endl;
  }
  return 0;
}
