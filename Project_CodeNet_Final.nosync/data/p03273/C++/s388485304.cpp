#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,i,j;
  cin >> H >> W;
  vector<vector<char>> v(H,vector<char>(W));
  vector<int> h(H),w(W);
  for(i=0;i<H;i++)for(j=0;j<W;j++)cin >> v[i][j];
  bool flag;
  for(i=0;i<H;i++){
    flag=1;
    for(j=0;j<W;j++){
      if(v[i][j]=='#'){
        flag=0;
        break;
      }
    }
    if(flag)h[i]=1;
  }
  for(i=0;i<W;i++){
    flag=1;
    for(j=0;j<H;j++){
      if(v[j][i]=='#'){
        flag=0;
        break;
      }
    }
    if(flag)w[i]=1;
  }
  for(i=0;i<H;i++){
    if(!h[i]){
      for(j=0;j<W;j++){
        if(!w[j])cout << v[i][j];
    }
    cout << endl;
    }
  }
}
