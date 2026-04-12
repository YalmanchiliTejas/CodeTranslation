#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int r, g, b; cin >> r >> g >> b;
  
  if (((g&0x1) == 0 && (b&0x3) == 0) || ((g&0x1) == 1 && (b&0x3) == 2)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}