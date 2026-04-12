#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  rep(i,H) cin >> a[i];
  vector<string> ans(H);
  rep(i,W){
    int num=0;
    rep(j,H) if(a[j][i]=='.') num++;
    if(num!=H) rep(j,H) ans[j].push_back(a[j][i]);
  }
  rep(i,H){
    rep(j,ans[i].size()){
      if(ans[i][j]=='#'){
        cout << ans[i] << endl;
        break;
      }
    }
  }

  return 0;
}
