#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  int h = 0;
  int w = 0; // eliminated numbers
  bool incomplete = true;
  while (incomplete){
    int count = 0;
    for (int i = 0; i < H - h; i++){
      bool white_flag = true;
      for (int j = 0; j < W; j++) {
        white_flag *= (A.at(i).at(j) == '.');
      }
      if (white_flag) {
        A.erase(A.begin()+i);
        h++;
        break;
      }
      count++;
    } 
    if (count == H - h) break;
  }
  while (incomplete){ 
    int count = 0;
    for (int j = 0; j < W -w; j++) {
      bool white_flag = true;
      for (int i = 0; i < H - h; i++){
        white_flag *= (A.at(i).at(j) == '.');
      }
      if (white_flag){
        for(int i = 0; i < H -h; i++){
          A.at(i).erase(A.at(i).begin()+j);
        }
        w++;
        break;
      }
      count++;
    }
    if (count == W -w) break;
  }
  
  for (int i = 0; i < H -h; i++){
    for (int j = 0; j < W - w; j++) {
      cout << A.at(i).at(j);
      if (j == W - w - 1) {
        cout << endl;
      }
    }
  }
}
