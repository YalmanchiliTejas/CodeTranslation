#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  char c[H][W];
  bool h[H]={};
  bool w[W]={};
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> c[i][j];
      if(c[i][j]=='#'){
        h[i]=true;
        w[j]=true;
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(h[i] && w[j])cout << c[i][j];
    }
    cout << endl;
  }
}




