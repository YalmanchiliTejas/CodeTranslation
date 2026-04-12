#include <bits/stdc++.h>
using namespace std;

int main(void){
 int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y ;
  int AB = min(X, Y) * 2 * C 
    + (X - min(X, Y)) * A 
    + (Y - min(X, Y)) * B;
  int D = X * A + Y * B;
  int E = max(X, Y) * 2 * C;
  cout << min(min(AB, D), E);
  
  return 0;
}