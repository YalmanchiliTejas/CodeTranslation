#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int H,W;
  cin>>H>>W;
  
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>vec[i][j];
    }
  }
  
  vector<bool> V(H,false);
  vector<bool> S(W,false);
  
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(vec[i][j]=='#'){
        V[i]=true;
        S[j]=true;
      }
    }
  }
  
  for(int i=0;i<H;i++){
    if(V[i]){
      for(int j=0;j<W;j++){
        if(S[j]){
          cout<<vec[i][j];
        }
      }
      cout<<endl;
    }
  }
}