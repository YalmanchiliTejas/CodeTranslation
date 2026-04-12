#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
  long wayA = A * X + B * Y;
  long wayB = C * max(X,Y) * 2;
  long wayC;
  if (X > Y) {
    wayC = C * Y * 2 + (X - Y) * A;
  } else {
    wayC = C * X * 2 + (Y - X) * B;
  } 
  long ans = min(wayA,min(wayB,wayC));
  cout << ans << endl;  
}
