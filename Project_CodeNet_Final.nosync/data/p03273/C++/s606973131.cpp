#include <bits/stdc++.h>
using namespace std;
int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>> S(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>S.at(i).at(j);
    }
  }
  vector<int> A(H),B(W);
  for(int i=0;i<H;i++){
    int count=0;
    for(int j=0;j<W;j++){
      if(S.at(i).at(j)=='.'){
        count++;
      }
    }
      if(count==W){
        A.at(i)=i+1;
      }
  }
  for(int j=0;j<W;j++){
    int count=0;
    for(int i=0;i<H;i++){
      if(S.at(i).at(j)=='.'){
        count++;
      }
    }
    if(count==H){
      B.at(j)=j+1;
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A.at(i)==0&&B.at(j)==0){
        cout<<S.at(i).at(j);
      }
    }
    if(A.at(i)==0){
      cout<<endl;
  }
  }
    cout<<endl;
}