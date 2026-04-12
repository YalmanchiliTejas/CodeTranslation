#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main(){
  int h,w; cin >> h >> w;
  std::vector<string> a(h);
  for (int i = 0; i < h; i++) {
    std::cin >> a[i];
  }

  //出力してokな行と列を決定するパート
  std::vector<bool> row(h,false),column(w,false);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        row[i] = true; column[j] = true;//一個でも#があれば出力ok
      }
    }
  }

  //出力してokかどうかを判定しつつ出力するパート
  for (int i = 0; i < h; i++) {
    if (row[i]) {//ここは出力してokな行ですか？を判定
      for (int j = 0; j < w; j++) {
        if (column[j]) {//ここは出力してokな列ですか？を判定
          std::cout << a[i][j];
        }
      }
      std::cout << '\n';
    }
  }
}
