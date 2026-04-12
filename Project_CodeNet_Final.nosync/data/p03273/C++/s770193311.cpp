#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
int X,Y;
string board[110];
bool goodx[110],goody[110];
int main(){
  cin>>X>>Y;
  rep(i,X)cin>>board[i];
  rep(i,X) rep(j,Y){
    if (board[i][j]=='#'){
      goodx[i]=true;
      goody[j]=true;
    }
  }
  rep(i,X){
    if(goodx[i]){
      rep(j,Y){
        if(goody[j]){
          cout<<board[i][j];
        }
      }
      cout<<endl;
    }
  }
  return 0;
}