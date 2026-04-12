#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  vector<bool> h_flag(h,false),w_flag(w,false);

  //入力から配列を生成し、判定するためのフラグの配列も更新する
  for (int i = 0 ; i < h ; i++) {
    for (int j =0 ; j < w ; j++) {
      cin >> a.at(i).at(j);
      if (a.at(i).at(j)== '#') {
        h_flag.at(i)=true;
        w_flag.at(j)=true;
      }
    }
  }
  
  for (int i = 0 ; i < h ; i++) {
    if (h_flag.at(i) == true) {
      for (int j = 0 ; j < w ; j++) {
        if (w_flag.at(j) == true) {
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}