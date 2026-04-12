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
  int count =0; //answerの列
  for (int i = 0; i < W; i++) {
    bool flag = true;
    for (int j = 0; j < H; j++) {
      if (data.at(j).at(i-count) != '.')  {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      for (int k = 0; k < H; k++) {
        for (int l = i-count; l < W-1; l++){
            data.at(k).at(l) = data.at(k).at(l+1);
        }
      }
      count++;
    }
    
  }
  
  for (int i = 0; i < H; i++) {
    bool flag = true;
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) != '.') {
        flag = false;
        break;
      }  
    }
    if (flag == false) {
        for (int j = 0; j < W - count; j++) {
          cout << data.at(i).at(j);
        }
        cout << endl;
    }
  }
}