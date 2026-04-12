#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i=0; i<H; i++) cin >> a.at(i);
  vector<bool> row(H, false), column(W, false);
  for (int i=0; i<H; i++)
    for (int j=0; j<W; j++)
      if (a.at(i).at(j) == '#') {
        row.at(i) = true;
        column.at(j) = true;
      }
  for (int i=0; i<row.size(); i++) {
    if (row.at(i)) {
      for (int j=0; j<column.size(); j++) {
        if (column.at(j)) {
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
  cout << endl;
}