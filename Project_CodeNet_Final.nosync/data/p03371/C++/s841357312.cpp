#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C ,X ,Y = 0;
  cin >> A >> B >> C >> X >> Y;
  
  int com = min(X, Y);
  
  int ans = min((A+B) * com, 2*C * com);
  
  int diff;
  if (X >= Y) {
    diff = X - Y;
    ans += min(A * diff, 2*C * diff);
  } else {
    diff = Y - X;
    ans += min(B * diff, 2*C * diff);
  }
  
  cout << ans << endl;
}