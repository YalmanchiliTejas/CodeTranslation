#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H,vector<char>(W));
  rep(i,H){
      rep(j,W){
          cin>>A[i][j];
      }
  }
  vector<bool> wx(W,false);
  vector<bool> hx(H,false);
  rep(i,H){
      rep(j,W){
          if(A[i][j]=='#'){
              hx[i]=true;
          }
      }
  }
  rep(j,W){
      rep(i,H){
          if(A[i][j]=='#'){
              wx[j]=true;
          }
      }
  }
  rep(i,H){
      if(hx[i]==false) continue;
      rep(j,W){
          if(wx[j]==true){
              cout<<A[i][j];
          }
      }
      cout<<endl;
  }
}