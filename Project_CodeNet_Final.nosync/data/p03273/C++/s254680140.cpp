#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int H,W;
  cin>>H>>W;
  vector<int> Hs(H,0),Ws(W,0);
  vector<vector<char>> Mat(H, vector<char>(W, ' '));
  for (int i = 0; i < H; i++) {
    bool skip = true;
    for (int j = 0; j < W; j++) {
      cin>>Mat[i][j];
      if (Mat[i][j] == '#') skip = false;
    }
    if (skip) Hs[i] = 1;
  }
  for (int i = 0; i < W; i++) {
    bool skip = true;
    for (int j = 0; j < H; j++) {
      if (Mat[j][i] == '#') skip = false;
    }
    if (skip) {
      Ws[i] = 1;
    }
  }
  for (int i = 0; i < H; i++) {
    bool ok = false;
    for (int j = 0; j < W; j++) {
      if (Hs[i] == 0 && Ws[j] == 0) ok = true, cout<<Mat[i][j];
    }
    if(ok) cout<<"\n";
  }
  return 0;
}