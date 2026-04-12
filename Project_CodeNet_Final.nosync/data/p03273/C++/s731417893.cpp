#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char grid0[110][110];
char grid1[110][110];
char grid2[110][110];

int main(){
  int h,w;
  cin>>h>>w;
  rep(i,h)rep(j,w){
    cin>>grid0[i][j];
  }
  int H=0;
  rep(hi,h){
    bool flag=0;
    rep(wi,w){
      if(grid0[hi][wi]=='#')flag=1;
    }
    if(flag){
      rep(wi,w){
        grid1[H][wi]=grid0[hi][wi];
      }
      H++;
    }
  }
  int W=0;
  rep(wi,w){
    bool flag=0;
    rep(hi,H){
      if(grid1[hi][wi]=='#')flag=1;
    }
    if(flag){
      rep(hi,H){
        grid2[hi][W]=grid1[hi][wi];
      }
      W++;
    }
  }
  rep(i,H){
    rep(j,W){
      cout<<grid2[i][j];
    }
    cout<<endl;
  }
}
