#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;cin>>H>>W;
  vector<vector<char>> a(H,vector<char>(W));
  vector<int> tate(H,false);
  vector<int> yoko(W,false);
  for(int x=0; x<H; x++){
    for(int y=0; y<W; y++){
      cin>>a[x][y];
      if(a[x][y]=='#'){
        tate[x]=true;
        yoko[y]=true;
      }
    }
  }
  for(int x=0; x<H; x++){
    for(int y=0; y<W; y++){
      if(tate[x]&&yoko[y])cout<<a[x][y];
    }
    if(tate[x])cout<<endl;
  }
}