#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  
  vector<vector<char>> A(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A.at(i).at(j);
    }
  }
  
  vector<int> L(H),R(W);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A.at(i).at(j)=='#'){
        L.at(i)=1;
        R.at(j)=1;
      }
    }
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(L.at(i)==1&&R.at(j)==1){
        cout<<A.at(i).at(j);
      }
      if(j==W-1&&L.at(i)==1) cout<<endl;
    }
  } 
}