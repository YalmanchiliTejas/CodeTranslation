#include <bits/stdc++.h>
using namespace std;

int main() {

  int h, w;
  cin >> h >> w;

  // load matrix
  vector<vector<char>> a(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < w; j++)
      a.at(i).at(j) = row[j];
  }

  // check: -> row
  for (int i = 0; i < h; i++) {
    bool is_delete = false;
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) == '.' || a.at(i).at(j) == '_') {
        is_delete = true;
      } else {
        is_delete = false;
        break;
      }
    }
    // delete: -> row
    if (is_delete) {
      for (int j = 0; j < w; j++)
        a.at(i).at(j) = '_';
    }
  }

  // check: -> col
  for (int j = 0; j < w; j++) {
    bool is_delete = false;
    for (int i = 0; i < h; i++) {
      if (a.at(i).at(j) == '.' || a.at(i).at(j) == '_') {
        is_delete = true;
      } else {
        is_delete = false;
        break;
      }
    }
    // delete: -> col
    if (is_delete) {
      for (int i = 0; i < h; i++)
        a.at(i).at(j) = '_';
    }
  }

  // output
  for (int i = 0; i < h; i++) {
    string buf = "";
    for (int j = 0; j < w; j++) {
      if (a.at(i).at(j) == '_')
        continue;
      else
        buf += a.at(i).at(j);
    }
    if (buf.size() > 0) cout << buf << endl;
  }

}
