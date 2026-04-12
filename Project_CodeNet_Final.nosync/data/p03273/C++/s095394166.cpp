#include <bits/stdc++.h>
using namespace std;

int main() {
  int h;
  cin >> h;
  int w;
  cin >> w;
  vector<vector <char>> a(h, vector<char>(w));
  for (int i = 0; i < h; i = i + 1) {
    for (int j = 0; j < w; j = j + 1) {
      cin >> a.at(i).at(j);
    }
  }
  //vector<vector<bool>> judge(h, vector<bool>(w, true));
  for (int i = 0; i < h; i = i + 1) {
    int count = 0;
    for (int j = 0; j < w; j = j + 1) {
      if (a.at(i).at(j) == '.') {
        count = count + 1;
      }
    }
    if (count == w) {
      for (int j = 0; j < w; j = j + 1) {
        a.at(i).at(j) = ' ';
      }
    }
  }
  
  for (int j = 0; j < w; j = j + 1) {
    int count = 0;
    for (int i = 0; i < h; i = i + 1) {
      if (a.at(i).at(j) == '.' || a.at(i).at(j) == ' ') {
        count = count + 1;
      }
    }
    if (count == h) {
      for (int i = 0; i < h; i = i + 1) {
        a.at(i).at(j) = ' ';   
      }
    }
  }
  
  for (int i = 0; i < h; i = i + 1) {
    int count = 0;
    for (int j = 0; j < w; j = j + 1) {
      if (a.at(i).at(j) != ' ') {
        cout << a.at(i).at(j);
      } else {
        count = count + 1;
      }
    }
    if (count != w) {
      cout << endl;
    }
  }
}

