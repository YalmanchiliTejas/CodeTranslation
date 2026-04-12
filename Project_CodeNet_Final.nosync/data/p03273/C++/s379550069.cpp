#include <bits/stdc++.h>
using namespace std;

int main() {

  int H, W;
  cin >> H >> W;
  
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a[i];
  }

  vector<bool> deleteH(H);
  vector<bool> deleteW(W);

  for (int i = 0; i < H; i++) {
    bool valid = true;
    for (int j = 0; j < W; j++) {
       if (a[i][j] == '#') {
         valid = false;
       }
    }
    if (valid) {
      deleteH[i] = true;
    }
  }

  for (int i = 0; i < W; i++) {
    bool valid = true;
    for (int j = 0; j < H; j++) {
       if (a[j][i] == '#') {
         valid = false;
       }
    }
    if (valid) {
      deleteW[i] = true;
    }
  } 

  for (int i = 0; i < H; i++) {
    if (!deleteH[i]) {
      for (int j = 0; j < W; j++) {
        if (!deleteW[j]) {
          cout << a[i][j];
        }
      }
      cout << endl;
    }
  }

}