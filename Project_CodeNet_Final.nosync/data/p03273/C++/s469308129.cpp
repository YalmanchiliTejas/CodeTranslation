#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  rep(i,h) cin >> a[i];

  rep(i,h){
    rep(j,w){
      if(a[i][j] == '#'){
        row[i] = true;
        col[j] = true;
      }
    }
  }

  rep(i,h){
    if(row[i]){
      rep(j,w){
        if(col[j]){
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }

  return 0;
}
