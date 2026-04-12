#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> a(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) cin >> a.at(i).at(j);
  }
  
  bool check;
  
  //行のチェック
  for (int i = 0; i < h; i++) {
    check = true;
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) == '#') check = false;
    }
    if (check) {
      for (int j = 0; j < w; j++) a.at(i).at(j) = '0';
    }
  }
  
  //列のチェック
  for (int j = 0; j < w; j++) {
    check = true;
    for (int i = 0; i < h; i++) {
      if (a.at(i).at(j) == '#') check = false;
    }
    if (check) {
      for (int i = 0; i < h; i++) a.at(i).at(j) = '0';
    }
  }
  
  int count;
    
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) != '0') cout << a.at(i).at(j);
    }
    //すべて白でない行のみ改行する
    count = 0;
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) == '0') count++;
    }
    if (count != w) cout << endl;
  }
 
}