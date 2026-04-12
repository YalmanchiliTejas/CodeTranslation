#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  // ABピザを買わない場合
  int sum1 = A*X+B*Y;
  // できるだけABピザを買う場合(minに合わせる)
  int sum2 = C*2*min(X, Y);
  if (X < Y) {
    sum2 += B*(Y-X);
  }
  else if (X > Y) {
    sum2 += A*(X-Y);
  }
  // できるだけABピザを買う場合(maxに合わせる)
  int sum3 = C*2*max(X, Y);
  int ans = min(sum1, min(sum2, sum3));
  cout << ans << endl;
}