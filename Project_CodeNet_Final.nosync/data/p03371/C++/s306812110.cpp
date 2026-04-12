#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int main() {
  int A,B,C,X,Y,Z;
  int sum=0;
  cin >> A >> B >> C >> X >> Y;
  if(A + B >= 2*C) { // Cで買ったらお得
    if(X >= Y) { // 2*Y枚はCを買う AのX枚をどっちで買うか
      sum += 2*Y*C;
      sum += min((X-Y)*A, 2*(X-Y)*C);
    } else {
      sum += 2*X*C;
      sum += min((Y-X)*B, 2*(Y-X)*C);
    }
  } else {
    sum += X * A;
    sum += Y * B;
  }
  cout << sum << endl;
  return 0;
}
