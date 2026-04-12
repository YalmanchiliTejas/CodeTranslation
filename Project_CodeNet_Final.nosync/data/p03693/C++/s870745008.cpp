#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b, ret;
  cin >> r >> g >> b;
  ret = 100*r + 10*g + b;
  if (ret % 4 == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}