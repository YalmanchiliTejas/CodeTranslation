#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,i,j,x=1;
  cin >> n>>m;
  vector <vector<char>> hyou(n,vector<char>(m));
  //入力と横チェック
  for(i=0;i<n;i++){
      for(j=0;j<m;j++){
          cin>>hyou[i][j];
       //   cout<<hyou[i][j];
          if(hyou[i][j]=='#') x=0;
      }
      if(x){
          for(j=0;j<m;j++) hyou[i][j]='0';
      } 
      //cout<<endl;
      x=1;
  }
  for(i=0;i<m;i++){
      for(j=0;j<n;j++){
          if(hyou[j][i]=='#') x=0;
      }
      if(x){
          for(j=0;j<n;j++) hyou[j][i]='0';
      } 
      x=1;
  }
  for(i=0;i<n;i++){
      x=0;
      for(j=0;j<m;j++){
          if(hyou[i][j]!='0') {
              cout<<hyou[i][j];
              x=1;
              }
      }
      if(x) cout<<endl;
  }
}