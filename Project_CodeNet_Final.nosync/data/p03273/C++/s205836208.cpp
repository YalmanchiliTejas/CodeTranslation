#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int count=0;
  int H,W;
  cin>>H>>W;
  vector<int>tate(H,0);
  vector<int>yoko(W,0);
  vector<vector<int>>hyou;
  hyou.resize(H);
  rep(i,H) hyou[i].resize(W);
  rep(i,H){
    rep(j,W){
      char x;
      cin>>x;
      if(x=='#')
        hyou[i][j]=1;
      else
        hyou[i][j]=0;
    }
  }
  rep(i,H){
    rep(j,W){
      tate[i]+=hyou[i][j];
    }
  }
  rep(i,W){
    rep(j,H){
      yoko[i]+=hyou[j][i];
    }
  }
  rep(i,H){
    rep(j,W){
      if(tate[i] and yoko[j]){
        if(hyou[i][j]){
          cout<<"#";
        }
        else cout<<".";
      }
    }
    cout<<endl;
  }
}
