#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<vector<char>> data(h, vector<char>(w));
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  bool flag = false;
  for (int i = h-1; i > -1; i--) {
    for (int j = 0; j < w; j++) {
      if(data.at(i).at(j) == '#') break;
      if(j==w-1) {
        for (int k = i; k < data.size()-1; k++) {
          data.at(k) = data.at(k+1);
        }
        data.pop_back();
      }
    }
  }
  for (int j = w-1; j > -1; j--) {
    for (int i = 0; i < data.size(); i++) {
      if(data.at(i).at(j) == '#') break;
      if(i==data.size()-1) {
        for (int k = 0; k < data.size(); k++) {
          for (int l = j; l < data.at(k).size()-1; l++) {
            data.at(k).at(l) = data.at(k).at(l+1);
          }
          data.at(k).pop_back();
        }
      }
    }
  }
  
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data.at(i).size(); j++) {
      cout << data.at(i).at(j);
    }
    cout << endl;
  }
}