#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int main() {
  //input
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  //calc
  int a, b, x, y;
  if ( X < Y ) {
    x = X; y = Y; a = A; b = B;
  }
  else {
    x = Y; y = X; a = B; b = A;
  }
  int answer = 0;
  if ( a + b < 2 * C ) {
    answer = x * (a+b);
  }
  else {
    answer = x * 2 * C;
  }
  if ( y > x ) {
    int diff = y - x;
    if ( b < 2 * C ) {
      answer += b * diff;
    }
    else {
      answer += 2 * C * diff;
    }
  }
  //output
  cout << answer << endl;
}