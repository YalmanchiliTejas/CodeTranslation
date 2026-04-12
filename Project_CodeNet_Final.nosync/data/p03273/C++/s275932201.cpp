#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> a(h, vector<char>(w));
  for (int i=0; i<h; i++){
    for (int j=0; j<w; j++){
      cin >> a.at(i).at(j);
    }
  }
  // h行w列の行列aに"."や"#"を入力
  
  vector<bool> row(h, 1), column(w, 1);
  // 各々の行や列を取り除くか判定するフラグをONにしておく
  
  for (int i=0; i<h; i++){
    for (int j=0; j<w; j++){
      if (a.at(i).at(j) == '#'){
        row.at(i) = 0;
        // ある行の要素w個のうち1つでも"#"があれば
        // 取り除くフラグを解除する
      }
    }
  }
  
  for (int j=0; j<w; j++){
    for (int i=0; i<h; i++){
      if (a.at(i).at(j) == '#'){
        column.at(j) = 0;
        // ある列の要素h個のうち1つでも"#"があれば
        // 取り除くフラグを解除する
      }
    }
  }
  
  for (int i=0; i<h; i++){
    if (row.at(i) == 0){
      for (int j=0; j<w; j++){
        if (column.at(j) == 0){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
