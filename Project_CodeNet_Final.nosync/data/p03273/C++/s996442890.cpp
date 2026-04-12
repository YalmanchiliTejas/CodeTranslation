#include <iostream>
using namespace std;
 
int H, W;
string A[100];
 
bool check() {
  for (int i = 0; i < H; i++) {
    bool ok = true;
    for (int j = 0; j < W; j++) {
      if (A[i][j] == '#') {
        ok = false;
      }
    }
    if (ok) {
      for (int k = i; k < H-1; k++) {
        swap(A[k],A[k+1]);
      }
      H--;
      return true;
    }
  }
  for (int j = 0; j < W; j++) {
    bool ok = true;
    for (int i = 0; i < H; i++) {
      if (A[i][j] == '#') {
        ok = false;
      }
    }
    if (ok) {
      for (int k = 0; k < H; k++) {
        A[k] = A[k].substr(0,j)+A[k].substr(j+1);
      }
      W--;
      return true;
    }
  }
  return false;
}
int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    cin >> A[i];
  }
  while (check());
  for (int i = 0; i < H; i++) {
    cout << A[i] << endl;
  }
  return 0;
}