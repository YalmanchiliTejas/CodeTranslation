#include <bits/stdc++.h>
using namespace std;

int main() {
  int H = 0, W = 0, k = 0, l = 0;
  cin >> H >> W;
  
  int tate = H, yoko = W;
  
  vector<vector<char>> a(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
   for (int j = 0; j < W; j++) {
     cin >> a.at(i).at(j);
   }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++){
      if (a.at(i).at(j) == '#') {
        break;
      }
      if (j == a.at(i).size() - 1) {
        tate--;
      }
    }
  }
  
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (a.at(j).at(i) == '#') {
        break;
      }
      if (j == a.size() - 1) {
        yoko--;
      }
    }
  }
  
  vector<vector<char>> b(tate, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        for (int m = 0; m < W; m++) {
          b.at(k).at(m) = a.at(i).at(m);
        }
        k++;
        break;
      }
      if (j == a.at(i).size() - 1) {
        break;
      }
    }
  }
  
  vector<vector<char>> c(tate, vector<char>(yoko));
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < tate; j++) {
      if (b.at(j).at(i) == '#') {
        for (int m = 0; m < tate; m++) {
          c.at(m).at(l) = b.at(m).at(i);
        }
        l++;
        break;
      }
      if (j == b.size() - 1) {
        break;
      }
    }
  }
  
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < l; j++){
      cout << c.at(i).at(j);
    }
    cout << endl;
  }
}
