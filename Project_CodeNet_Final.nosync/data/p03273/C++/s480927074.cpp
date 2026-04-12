#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  char a[H][W];
  vector<int> hb(H);
  vector<int> wb(W);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a[i][j];
      if(a[i][j]=='#'){
        hb.at(i)++;
        wb.at(j)++;
      }
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(hb.at(i)>0 && wb.at(j)>0) cout << a[i][j];
    }
    if(hb.at(i)>0) cout << endl;
  }
}