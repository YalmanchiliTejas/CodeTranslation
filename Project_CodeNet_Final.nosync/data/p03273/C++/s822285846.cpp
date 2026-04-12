#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H, vector<char>(W));
  vector<char> vecH(W, '.');
  vector<char> R(0);
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++) {
      cin >> vec.at(i).at(j);
    }
  }
  
  int count = 0;
  for (int i = 0; i < H; i++) {
    if (vec.at(i) != vecH) {
      for (int j = 0; j < W; j++) {
        R.push_back(vec.at(i).at(j));
      }
      count++;
    }
  }
  
  vector<vector<char>> R2(W, vector<char>(count));
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < count; j++) {
      R2.at(i).at(j) = R.at(j * W + i);
    }
  }
  
  int count2 = 0;
  vector<char> vecW(count, '.');
  vector<char> R3(0);
  for (int i = 0; i < W; i++) {
    if (R2.at(i) != vecW) {
      for (int j = 0; j < count; j++) {
      	R3.push_back(R2.at(i).at(j));
      }
      count2++;
    }
  }
  
  vector<vector<char>> R4(R2.at(0).size(), vector<char>(count2));
  for (int i = 0; i < R2.at(0).size(); i++) {
    for (int j = 0; j < count2; j++) {
      R4.at(i).at(j) = R3.at(j * count + i);
    }
  }
  
  for (int i = 0; i < R4.size(); i++) {
    for (int j = 0; j < R4.at(0).size(); j++) {
      cout << R4.at(i).at(j);
    }
    cout << endl;
  }

}
