#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const long long INF = 1LL << 60;

int main() {
  int H, W; cin>>H>>W;
  vector<vector<int>> G(H, vector<int>(W));
  vector<int> tate(H);
  vector<int> yoko(W);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      char C; cin>>C;
      if(C=='.') G[i][j]=0;
      if(C=='#'){
        G[i][j]=1;
        tate[i]=1;
        yoko[j]=1;
      } //#
    } //j
  } //i
  int K=0;
  for(int j=W-1; j>=0; j--){
    if(yoko[j]==1){
      K=j; //右端
      break;
  }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(tate[i]==1 && yoko[j]==1){
        if(G[i][j]==0) cout<<".";
        if(G[i][j]==1) cout<<"#";
        if(j==K) cout<<endl;
        }
    } //j
  } //i
}
