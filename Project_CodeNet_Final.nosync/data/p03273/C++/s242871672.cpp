#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H, ".");
  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }
  
  // 横一列の圧縮
  for (int i = 0; i < H; i++) {
    bool erase_flag = true;
    
    for (int j = 0; j < W; j++) {
      if(a.at(i).at(j) == '#'){
        erase_flag = false;
        break;
      }
    }
    
    if(erase_flag) {
      for (int j = 0; j < W; j++) {
        a.at(i).at(j) = '-';
      }
    }
  }
  
  // 縦一列の圧縮
  for (int i = 0; i < W; i++) {
    bool erase_flag = true;
    
    for (int j = 0; j < H; j++) {
      if(a.at(j).at(i) == '#'){
        erase_flag = false;
        break;
      }
    }
    
    if(erase_flag) {
      for (int j = 0; j < H; j++) {
        a.at(j).at(i) = '-';
      }
    }
  }
  
  
  for (int i = 0; i < H; i++) {
    bool newline_flag = true;
    int char_count = 0;
    
    for (int j = 0; j < W; j++) {
      if(a.at(i).at(j) != '-'){
        cout << a.at(i).at(j);
      }
      else {
        char_count++;
        if(char_count >=W) {
          newline_flag = false;
        }
      }
    }
    if(newline_flag)
      cout << endl;
  }
}