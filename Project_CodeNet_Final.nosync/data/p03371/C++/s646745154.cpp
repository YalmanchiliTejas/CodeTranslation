#include <bits/stdc++.h>
using namespace std;
int main () {
  long long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long long count = 0;
  if(C * 2 < A + B) {
    int mini = min(X, Y);
    count += mini * 2 * C;
    X -= mini;
    Y -= mini;
    if(X > Y) {
      if (C * 2 > A)  count += A * X;
      else count += C * 2 * X;
    } else {
      if (C * 2 > B)  count += B * Y;
      else count += C * 2 * Y;
    }
  } else {
    count += X * A;
    count += Y * B;
  }
  cout << count << endl;
  return 0;
}
