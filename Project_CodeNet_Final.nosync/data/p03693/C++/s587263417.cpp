#include<bits/stdc++.h>
using namespace std;

int main () {
  int r, g, b, A;
  cin >> r >> g >> b >> A;
  A = 100*r + 10*g + b;
  if (A % 4 == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}