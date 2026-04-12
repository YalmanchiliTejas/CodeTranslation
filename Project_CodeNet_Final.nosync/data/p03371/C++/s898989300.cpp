#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y, sum1, sum2, count;
  cin >> A >> B >> C >> X >> Y;
  sum1 = A * X + B * Y;
  for(int i = 0; i <= max(X,Y); i++) {
    if(i <= X && i <= Y) {
      sum2 = (X - i) * A + (Y - i) * B + (2 * i) * C;
      if(sum2 <= sum1) {
        sum1 = sum2;
      }
    }
    else if(i >= max(X,Y)) {
      sum2 = 2 * i * C;
      if(sum2 <= sum1) {
        sum1 = sum2;
      }
    }
  }
  cout << sum1 << endl;
}
