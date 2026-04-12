#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> p(H,vector<char>(W));
  vector<int> t(H);
  vector<int> y(W);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>p[i][j];
      if(p[i][j]=='#'){
        t[i]++;
        y[j]++;
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(t[i]&&y[j]){
        cout<<p[i][j];
      }
    }
    cout<<endl;
  }
}