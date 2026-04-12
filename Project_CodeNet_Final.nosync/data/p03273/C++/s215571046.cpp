#include <bits/stdc++.h>
using namespace std;

void printline(vector<vector<char>> a, vector<vector<bool>> b, int line_n) {

  bool vacant = true;
  for (char element : a.at(line_n)) {
    if (element == '#') {
      vacant = false;
      break;
    }
  }

  if (!vacant) {
    for (int j = 0; j < a.at(0).size(); j++) {
      if (b.at(line_n).at(j)) {
        cout << a.at(line_n).at(j);
      }
    }
    cout << endl;
  }
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> a(h, vector<char>(w, '.'));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a.at(i).at(j);
    }
  }

  vector<vector<bool>> b(h, vector<bool>(w, true));

  for (int i = 0; i < h; i++) {
    bool dotline = true;
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) == '#') {
        dotline = false;
      }
    }
    if (dotline) {
      for (int j = 0; j < w; j++) {
        b.at(i).at(j) = false;
      }
    }
  }

  for (int j = 0; j < w; j++) {
    bool dotcolumn = true;
    for (int i = 0; i < h; i++) {
      if (a.at(i).at(j) == '#') {
        dotcolumn = false;
      }
    }
    if (dotcolumn) {
      for (int i = 0; i < h; i++) {
        b.at(i).at(j) = false;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    printline(a, b, i);
  }
}
