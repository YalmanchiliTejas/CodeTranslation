#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
  int h,w; cin>>h>>w;
  char grid[h][w];
  rep(i, h){
    rep(j, w){
      cin>>grid[i][j];
    }
  }
  
  int yoko[h]={0};
  
  rep(i, h){
    bool siro1=true;
    rep(j, w){
      if(grid[i][j]!='.'&&grid[i][j]!='s'){siro1=false;
                          break;}
    }
      if(siro1){
          rep(j, w){grid[i][j]='s';}
        yoko[i]=1;
      }
  }
        
  
  
   rep(j, w){
    bool siro1=true;
    rep(i, h){
      if(grid[i][j]!='.'&&grid[i][j]!='s'){siro1=false;
                          break;}
    }
      if(siro1){
          rep(i, h){grid[i][j]='s';}
      }
  }
  
  rep(i, h){
    rep(j, w){
      if(yoko[i]==1) continue;
      if(grid[i][j]!='s')cout<<grid[i][j];
      if(j==w-1)cout<<endl;
    }
  }
  

}
