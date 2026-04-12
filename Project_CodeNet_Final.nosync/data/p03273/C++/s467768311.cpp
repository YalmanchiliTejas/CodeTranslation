#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
    }
  }
  vector<bool> row(h,false);
  vector<bool> col(w,false);
  rep(i,h){
    rep(j,w){
      if(s[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }
  rep(i,h){
    if(row[i]){
      rep(j,w){
        if(col[j]){
          cout << s[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}
