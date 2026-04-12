#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  vector<vector<char>> temp(H, vector<char>(W));
  vector<vector<char>> R(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }
  
  int tempH = 0;
  for (int i = 0; i < H; i++) {
    bool flag = true;
    for(int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        flag = false;
        break;
      }
    }
    if (!flag) {
      for(int j = 0; j < W; j++) {
        temp.at(tempH).at(j) = a.at(i).at(j);
      }
      tempH++;
    }
  }
  
  int tempW = 0;
  for (int i = 0; i < W; i++) {
    bool flag = true;
    for(int j = 0; j < tempH; j++) {
      if (temp.at(j).at(i) == '#') {
        flag = false;
        break;
      }
    }
    if (!flag) {
      for(int j = 0; j < H; j++) {
        R.at(j).at(tempW) = temp.at(j).at(i);
      }
      tempW++;
    }
  }
  
  for (int i = 0; i < tempH; i++) {
    for(int j = 0; j < tempW; j++) {
      cout << R.at(i).at(j);
    }
    cout << endl;
  }

}
