#include <bits/stdc++.h>
using namespace std;

int main() {
  int tate;
  cin >> tate;
  int yoko;
  cin >> yoko;
  
  vector<vector<char>> moji(tate, vector<char>(yoko, ' '));
  
  for (int i = 0; i < tate; i = i + 1) {
    for (int j = 0; j < yoko; j = j + 1) {
      cin >> moji.at(i).at(j);
    }
  }
  
  vector<vector<bool>> line(tate, vector<bool>(yoko, true));
  
  for (int i = 0; i < tate; i = i + 1) {
    if (moji.at(i) == vector<char>(yoko, '.')) {
      line.at(i) = vector<bool>(yoko, false);
    }
  }
  
  for (int j = 0; j < yoko; j = j + 1) {
    
    int count = 0;
    
    for (int i = 0; i < tate; i = i + 1) {
      if (moji.at(i).at(j) == '.') {
        count = count + 1;
      }
    }
    if (count == tate) {
      for (int i = 0; i < tate; i = i + 1) {
        line.at(i).at(j) = false;
      }
    }
  }
  
  for (int i = 0; i < tate; i = i + 1) {
    
    bool kaigyou = false;
    
    for (int j = 0; j < yoko; j = j + 1) {
      if (line.at(i).at(j) == true) {
        cout << moji.at(i).at(j);
        kaigyou = true;
      }
    }
    if (kaigyou == true) {
      cout << endl;
    }
    
  }
}