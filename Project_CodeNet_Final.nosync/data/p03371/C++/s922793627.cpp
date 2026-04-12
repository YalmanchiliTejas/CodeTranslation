#include<bits/stdc++.h>
using namespace std;

int main() {

  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  if(A + B <= 2 * C) {
    cout << A * X + B * Y;
  }else {
    if(X > Y) cout << min(2 * C * X, 2 * C * Y + A * (X - Y)) << endl;
    else if(X == Y) cout << 2 * C * X << endl;
    else cout << min(2 * C * Y, 2 * C * X + B *(Y - X)) << endl;
  }
}