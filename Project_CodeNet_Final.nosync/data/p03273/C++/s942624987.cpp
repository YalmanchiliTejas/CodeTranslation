#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  int a[H]={};
  int b[W]={};
  string S[H];
  for (int i=0;i<H;i++){
    cin >> S[i];
    for(int j=0;j<W;j++){
      b[j]+=S[i][j]=='.'?1:0;
      a[i]+=S[i][j]=='.'?1:0;
    }
  }
  for (int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if (a[i]<W and b[j]<H){
        cout << S[i][j];
      }
    }
    cout << endl;
  }
}
