#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

vector<vector<char>> f(vector<vector<char>> const &a, int h, int w) {
  vector<vector<char>> b;
  rep(i,0,w-1) {
    vector<char> col;
    rep(j,0,h-1) {
      col.push_back(a.at(j).at(i));
    }
    b.push_back(col);
  }
  return b;
}

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> h;
  rep(i,0,H-1) {
    char a;
    vector<char> row;
    rep(j,0,W-1) {
      cin >> a;
      row.push_back(a);
    }
    h.push_back(row);
  }

  rep(i,0,H-1) {
    bool skip_h = true;
    rep(j,0,W-1) {
      if (h[i][j] == '#') skip_h = false;
    }
    if (skip_h) {
      h.erase(h.begin()+i);
      i--;
      H--;
    }
  }

  h = f(h, H, W);

  rep(i,0,W-1) {
    bool skip_v = true;
    rep(j,0,H-1) {
      if (h[i][j] == '#') skip_v = false;
    }
    if (skip_v) {
      h.erase(h.begin()+i);
      i--;
      W--;
    }
  }

  h = f(h, W, H);

  cout << endl;
  for (auto p : h) {
    for (char i : p) cout << i;
    cout << endl;
  }

  return 0;
}
