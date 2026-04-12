#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int H, W;
  cin >> H >> W;
  char a[H][W];
  vector<int> tate(W), yoko(H); 
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(a[i][j] == '#') { tate[j] = 1; yoko[i] = 1; }
    }
  }

  for(int i = 0; i < H; i++) {
    if(yoko[i] == 1){
    for(int j = 0; j < W; j++) {
     if(tate[j] == 1) cout << a[i][j]; 
    }
    cout << endl;
    }
  }


  return 0;
}