#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int H,W; cin>>H>>W;
  vector<bool>A(H+W,true);
  vector<vector<char>>B(H,vector<char>(W));
  rep(i,H){
    string S; cin>>S;
    rep(j,W){B[i][j]=S.at(j);if(S.at(j)=='#'){A[i]=false; A[H+j]=false;}}
  }
  rep(i,H){
    bool D=false;
    rep(j,W){if(!A[i]&&!A[H+j]){cout<<B[i][j]; D=true;}}
    if(D)cout<<endl;
  }
}