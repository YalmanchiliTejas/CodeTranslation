#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, H, X, Y;
  cin >> A >> B >> H >> X >> Y;
  int price = 0;
  
  if (A + B <= H * 2) {
    price = A * X + B * Y;
  }
  else {
    int delt = max (X-Y, Y-X);
    int nocori;
    if (X > Y) nocori = A;
    else nocori = B;
    price = min( H * min (X, Y) * 2 + delt * nocori, H * max (X, Y) * 2);
  }
  
  cout << price << endl;
}