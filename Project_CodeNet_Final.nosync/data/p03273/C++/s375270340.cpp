#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin>>h>>w;
  string a[h];
  for (int i=0; i<h; i++) cin>>a[i];

  set<int> row;
  for (int i=0; i<h; i++) {
    bool ok = true;
    for (int j=0; j<w; j++) {
      if (a[i][j] == '#') {
        ok = false;
        break;
      }
    }
    if (ok) {
      row.insert(i);
    }
  }
  set<int> column;
  for (int j=0; j<w; j++) {
    bool ok = true;
    for (int i=0; i<h; i++) {
      if (a[i][j] == '#') {
        ok = false;
        break;
      }
    }
    if (ok) {
      column.insert(j);
    }
  }
  for (int i=0; i<h; i++) {
    if (row.find(i) != row.end()) {
      continue;
    }
    for (int j=0; j<w; j++) {
      if (column.find(j) != column.end()) {
        continue;
      }
      cout<<a[i][j];
    }
    cout<<endl;
  }
}