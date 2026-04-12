#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y; C *= 2;
  long t;
  if(A + B <= C) t = A * X + B * Y;
  else if(A >= C && B >= C) t = max(X, Y) * C;
  else if(A >= C && B <= C) t = X * C + max(Y - X, 0) * B;
  else if(A <= C && B >= C) t = Y * C + max(X - Y, 0) * A;
  else if(A <= C && B <= C) t = min(X, Y) * C + max(X - Y, Y - X) * ((max(X - Y, Y - X) == X - Y) ? A : B);
  else t = -1;
  cout << t << endl;
}