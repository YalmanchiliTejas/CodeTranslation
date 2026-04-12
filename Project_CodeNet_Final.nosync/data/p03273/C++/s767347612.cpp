#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> d(H, vector<char>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> d.at(i).at(j);
    }
  }
  vector<int> h(H, 0);
  vector<int> w(W, 0);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (d.at(i).at(j) == '#') {
        h.at(i)=1;
        w.at(j)=1;
      }
    }
  }
  for (int i=0; i<H; i++) 
    if ( h.at(i)==1 ) {
      for (int j=0; j<W; j++) 
        if ( w.at(j)==1 ) cout << d.at(i).at(j);
      cout << endl;
    }
}
