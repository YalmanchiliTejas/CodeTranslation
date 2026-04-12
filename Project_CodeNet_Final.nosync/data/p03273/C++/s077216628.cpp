//結構苦労した

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int H, W;
  cin >> H >> W;

  //入力
  vector<string> vec(H);
  rep(i,H){
      cin >> vec.at(i);
  }

  //"#"が含まれる行と列をマーク
  vector<bool> row(H, false);  //行 rows
  vector<bool> col(W, false);  //列 columns

  rep(i,H){
    rep(j,W){
      if (vec.at(i).at(j) == '#'){
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }

  //出力
  rep(i,H){
      if (row[i]){
        rep(j,W){
          if (col[j]){
            cout << vec.at(i).at(j);
          }
        }
        cout << endl;
      }
  }

}
