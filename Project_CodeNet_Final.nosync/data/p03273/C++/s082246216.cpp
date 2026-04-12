#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int H, W;
  cin >> H >> W;
  string S[100];
  bool latte[100] = {}, malta[100] = {};
  for(int i = 0; i < H; i++) {
    cin >> S[i];
    for(int j = 0; j < W; j++) {
      if(S[i][j] == '#') {
        latte[i] = true;
        malta[j] = true;
      }
    }
  }
  for(int i = 0; i < H; i++) {
    bool output = false;
    for(int j = 0; j < W; j++) {
      if(latte[i] && malta[j]) {
        cout << S[i][j];
        output = true;
      }
    }
    if(output) cout << endl;
  }
}