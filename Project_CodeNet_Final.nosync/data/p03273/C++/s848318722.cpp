#include <bits/stdc++.h>
using namespace std;

bool has_black(string s) {
  for (char c: s) 
    if (c == '#') return true;
  
  return false; 
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<bool> mh(h, false);
  vector<bool> mw(w, false);
  
  vector<string> g(h);
  for (int i = 0; i < h; i++) {
    cin >> g[i];

    if (has_black(g[i])) {
      mh[i] = true;
    }
  }

  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (g[j][i] == '#') mw[i] = true;
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) 
      if (mh[i] && mw[j]) cout << g[i][j];
    
    if (mh[i]) cout << endl;
  }
}
