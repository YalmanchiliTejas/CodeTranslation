#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> BorW(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
    cin>>BorW.at(i).at(j);
    }
  }
  vector<int> A(H),B(W);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(BorW.at(i).at(j)=='#'){
        A.at(i)=1;
        break;
      }
    }
  }
  for(int j=0;j<W;j++){
    for(int i=0;i<H;i++){
      if(BorW.at(i).at(j)=='#'){
        B.at(j)=1;
        break;
      }
    }
  }
  for(int i=0;i<H;i++){
    if(A.at(i)==0)
      continue;
    for(int j=0;j<W;j++){
      if(B.at(j)==1)
        cout<<BorW.at(i).at(j);
    }
    cout<<endl;
  }
}