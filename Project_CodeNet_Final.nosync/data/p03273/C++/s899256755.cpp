#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
    cin >> data.at(i).at(j);
    }
  }
  
  int x =0; //answerの列の個数
  for (int i = 0; i < W; i++) {
    bool flag = false;
    for (int j = 0; j < H; j++) {
      if (data.at(j).at(i) == '#') {
        x++;
        flag = true;
        break;
      }
    }
    if (flag == false) {
        for (int k = 0; k < H; k++) {
          data.at(k).at(i) = '-';
        }
    }
  }
  
  int y=0;//answerの行の個数
  for (int i = 0; i < H; i++) {
    bool flag = false;
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '#') {
        y++;
        flag = true;
        break;
      }  
    }
    if (flag == false) {
        for (int k = 0; k < W; k++) {
          data.at(i).at(k) = '-';
        }
    }
  }
  vector<char> henkan = {};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) != '-') {
        henkan.push_back(data.at(i).at(j));
      }
    }
  }
  
  vector<vector<char>> answer(y, vector<char>(x));
  for (int i=0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      data.at(i).at(j) = henkan.at(i*x+j);
      cout << data.at(i).at(j);
      if (j == (x-1)) {
        cout << endl; // 末尾なら改行
      } 
    }
  }

  
  
}