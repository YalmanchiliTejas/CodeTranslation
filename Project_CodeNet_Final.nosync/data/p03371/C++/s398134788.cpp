#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int pizza = 0;
  int E = C*2;
  if (A+B <= E)
    pizza = A*X + B*Y;
  else if (E <= min(A,B))
    pizza = E*max(X,Y);
  else if (X > Y)
    pizza = E*Y + min(A,E)*(X-Y);
  else
    pizza = E*X + min(B,E)*(Y-X);
  cout << pizza << endl;
} 