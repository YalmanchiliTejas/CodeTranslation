#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> a(h);
  for (int i=0; i<h; i++) {
    cin >> a.at(i);
  }

  vector<bool> row(h,false);
  vector<bool> column(w,false);

  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (a.at(i).at(j) == '#') {
        row[i] = true;
        column[j] = true;
      }
    }
  }

  for (int i=0; i<h; i++) {
    if (row[i] == true) {
      for (int j=0; j<w; j++) {
         if (column[j] == true) {
           cout << a[i][j];
         }
      }
      cout << endl;
    }
  }

}
