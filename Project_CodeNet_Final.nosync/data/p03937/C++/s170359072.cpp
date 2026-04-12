#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int h,w;
  cin>>h>>w;
  char b[h+2][w+2];
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      cin>>b[i][j];
    }
  }
  for(i=0;i<=h;i++){
    b[i][0]='.';
    b[i][w+1]='.';
  }
  for(i=0;i<=w;i++){
    b[0][i]='.';
    b[h+1][i]='.';
  }
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      if(i==h && j==w)break;
      if(b[i][j]=='#'){
        if((b[i+1][j]=='.' && b[i][j+1]=='.') || (b[i+1][j]=='#' && b[i][j+1]=='#')){
          cout<<"Impossible";
          return 0;
        }
        if(i!=1 || j!=1){
          if((b[i-1][j]=='.' && b[i][j-1]=='.') || (b[i-1][j]=='#' && b[i][j-1]=='#')){
            cout<<"Impossible";
            return 0;
          }
        }
      }
    }
  }
  cout<<"Possible";
}