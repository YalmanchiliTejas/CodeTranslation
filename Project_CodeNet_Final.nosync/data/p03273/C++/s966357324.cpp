#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  string a[H];
  for (int i = 0; i < H; i++) cin >> a[i];
  
  bool x[W]={}, y[H]={};
  // cout << ' ';  for (bool j : x) cout << j << ' ';  cout << endl;  for (bool i : y) cout << i << endl;   cout << endl; 
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '#') {
        y[i] = true;
        x[j] = true;
      }
      // cout << ' ';  for (bool j : x) cout << j << ' ';  cout << endl;  for (bool i : y) cout << i << endl;   cout << endl; 
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (y[i] == false) continue;
    for (int j = 0; j < W; j++) {
      if (x[j] == true) {
        cout << a[i][j];
      }
    }
    cout << endl;
  }
}
