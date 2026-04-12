#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int given_number = 100*r + 10*g + b;
  int result = (given_number / 4) * 4;
  if (given_number == result) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}