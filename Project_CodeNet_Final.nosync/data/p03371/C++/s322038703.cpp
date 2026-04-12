#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  int sum = 0;
  int m = min(X,Y);
  
  if (A + B > C * 2) {
    sum += min(X,Y) * (C * 2);
    X -= m;
    Y -= m;

    if (X > 0 || Y > 0) {
      if (X > 0) {
        if (A > C * 2)
          sum += (C * 2) * X;
        else
          sum += A * X;
      }
      else {
        if (B > C * 2)
          sum += (C * 2) * Y;
        else
          sum += B * Y;
      }
    }
  }
  else {
    sum += A * X + B * Y;
    X -= m;
    Y -= m;
  }
   
  cout << sum << endl;  
}
