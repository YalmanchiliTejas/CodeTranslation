#include <bits/stdc++.h> 
using namespace std;

int main () {
  int H, W;
  cin >> H >> W;
  vector<string> phase(H);
  for (int i = 0; i < H; i++) {
    cin >> phase.at(i);
  }
  //ここまでで一応元のデータは入れ終えた
  vector<bool> vertical(H, true), horizontal(W, true);
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if(phase.at(i).at(j) != '.') {
        horizontal.at(j) = false;
        break;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(phase.at(i).at(j) != '.') {
        vertical.at(i) = false;
        break;
      }
    }
  }
  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      if(vertical.at(j) == false && horizontal.at(i) == false) {
        cout << phase.at(j).at(i);
      }
    }
    cout << endl;
  }
}
  
