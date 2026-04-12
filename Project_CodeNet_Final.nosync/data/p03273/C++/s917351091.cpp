#include <bits/stdc++.h>
#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;

signed main (){
  int H,W;
  cin>>H>>W;
  vector<string> a(H);
  rep(i,H){
    cin>>a[i];
  }
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  rep(i,H){
    rep(j,W){
      if(a[i][j]=='#'){
        row[i]=true;
        col[j]=true;
      }
    }
  }
  rep(i,H){
    if(row[i]){
      rep(j,W){
        if(col[j]){
          cout<<a[i][j] ;
        }
      }
      cout<<endl;
    }
  }
}
