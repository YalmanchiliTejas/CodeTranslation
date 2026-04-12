#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> V(H, vector<char>(W));
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      cin >> V[i][j];
    }
  }
  set<int> h, w;
  for (int i=0; i<H; i++) {
    h.insert(i);
  }
  for (int i=0; i<W; i++) {
    w.insert(i);
  }
  
  
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (V[i][j]=='#') {
        h.erase(i);
        w.erase(j);
      }
    }
  }
  for (int i=0; i<H; i++) {
    if (h.count(i)) {continue;}
    for (int j=0; j<W; j++) {
      if (w.count(j)) {continue;}
      cout << V[i][j];
    }
    cout << endl;
  }
} 
