#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  int x =0;
  cin >> A >> B >> C >> X >> Y;
  
  if (A+B<2*C) x=A*X+B*Y;
  else {
    x += min(X,Y)*2*C;
    if (X<Y) {
      if (B>2*C) x += (Y-X)*2*C;
      else x += (Y-X)*B;
    }
    else {
      if (A>2*C) x += (X-Y)*2*C;
      else x+= (X-Y)*A;
    }
  }

  cout << x << endl;

}

