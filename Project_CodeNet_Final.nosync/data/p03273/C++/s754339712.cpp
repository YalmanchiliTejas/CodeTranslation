#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector< string > S(H);
  for(int i = 0; i < H; i++) cin >> S[i];

  vector< int > row(H), col(W);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for(int i = 0; i < H; i++) {
    bool output = false;
    for(int j = 0; j < W; j++) {
      if(row[i] && col[j]) {
        cout << S[i][j];
        output = true;
      }
    }
    if(output) cout << endl;
  }
}
