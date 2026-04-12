#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];
  
  vector<bool> row(h, false);
  vector<bool> col(w, false);

  rep(i, h){
    rep(j, w){
      if(a[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }

  rep(i, h){
    if(row[i]){
      rep(j, w){
        if(col[j]) cout << a[i][j];
      }
      cout << endl;
    }
  }
}
