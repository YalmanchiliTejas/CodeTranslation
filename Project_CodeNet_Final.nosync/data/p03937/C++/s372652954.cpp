#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<char>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pll = pair<ll, ll>;

int main() {
  int h,w; cin>>h>>w;
  graph v(h,vector<char>(w));
  rep(i,h){
    rep(j,w){cin>>v[i][j];}
  }
  int i=0,j=0;
  bool b=true;
  while(true){
    if(i!=0){
      if(v[i-1][j]=='#'){b=false; break;}
    }
    if(j!=0){
      if(v[i][j-1]=='#'){b=false; break;}
    }
    if(i!=h-1&&j!=w-1){
      if((v[i][j+1]=='#'&&v[i+1][j]=='#')
         ||(v[i][j+1]=='.'&&v[i+1][j]=='.')){b=false; break;}
    }
    if(i==h-1 && j==w-1){break;} 
    bool d=false;
    if(i!=h-1){
      if(v[i+1][j]=='#'){v[i][j]='.'; i++;d=true;}
    }
    if(!d && j!=w-1){
      if(v[i][j+1]=='#'){v[i][j]='.'; j++;}
    }
  }
  if(b)cout<<"Possible";
  else{cout<<"Impossible";}
}