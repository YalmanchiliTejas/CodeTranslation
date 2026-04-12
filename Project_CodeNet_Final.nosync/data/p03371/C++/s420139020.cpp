#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int a, b, c;
  if(A+B>C*2)c=min(X, Y)*2;
  else c=0;
  
  if(A>C*2&&X>Y)c=X*2;
  if(B>C*2&&X<Y)c=Y*2;
  
  a=X-min(X, c/2);
  b=Y-min(Y, c/2);
  
  cout << A*a +B*b+C*c << endl;
  
}