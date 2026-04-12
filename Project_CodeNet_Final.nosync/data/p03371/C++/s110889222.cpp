#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int one = C*2*max(X,Y);
  int too = A*X+B*Y;
  int thr = X < Y ? B : A;
  int hoo = 2 * C * min(X, Y) + thr * abs(X-Y);
  cout << min(one,min(too,hoo)) << endl;
}
