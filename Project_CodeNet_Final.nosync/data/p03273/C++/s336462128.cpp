#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >>H>>W;
  bool a[H];
  for(int i=0;i<H;i++) a[i] = false;
  bool b[W];
  for(int j=0;j<W;j++) b[j] = false;
  char G[H][W];
  for(int i=0;i<H;i++){
    cin >> G[i];
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(G[i][j] == '#'){
        a[i] = true;
        b[j] = true;
      }
    }
  }
  for(int i=0;i<H;i++){
    bool x=false;
    for(int j=0;j<W;j++){
      if(a[i] && b[j]){
        cout << G[i][j];
        x=true;
      }
    }
    if(x) cout << endl;
  }
}