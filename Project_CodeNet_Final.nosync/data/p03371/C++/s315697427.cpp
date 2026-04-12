#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
// using ll = long long;
// using P = pair<int, int>;


int A, B, C, X, Y;

int main() {
  // A,B,C円
  // AピザをX枚，BピザをY枚

  cin >> A >> B >> C >> X >> Y;

  int res[3];
  //res = A * X + B * Y;

  res [0] = A * X + B * Y;
  res [1] = A * max(0,X-Y) + C * 2*Y;
  res [2] = B * max(0,Y-X) + C * 2*X;
  

  cout << min({res[0],res[1],res[2]}) << endl;
}
