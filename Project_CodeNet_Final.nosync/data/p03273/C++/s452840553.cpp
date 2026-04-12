#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin>>n>>m;
  char x[n][m];
  for(int i=0; i<n; ++i){
    string y;
    cin>>y;
    for(int j=0; j<m; ++j){
      x[i][j] = y[j];
    }
  }
  bool print[n][m];
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      print[i][j] = true;

  for(int i=0; i<n; ++i){
    int stat = true;
    for(int j=0; j<m; ++j){
      if( x[i][j] == '#' ){ stat = false;}
    }
    if( stat == true ){
      for(int j=0; j<m; ++j){
        print[i][j] = false;
      }
    }
  }
  for(int j=0; j<m; ++j){
    int stat = true;
    for(int i=0; i<n; ++i){
      if( x[i][j] == '#' ){ stat = false; }
    }
    if( stat == true ){
      for(int i=0; i<n; ++i){
        print[i][j] = false;
      }
    }
  }
  for(int i=0; i<n; ++i){
    bool stat = false;
    for(int j=0; j<m; ++j){
      if(print[i][j] == true){
        cout<<x[i][j];
        stat = true;
      }
    }
   if(stat == true){ cout<<"\n"; }
  }
  return 0;
}
