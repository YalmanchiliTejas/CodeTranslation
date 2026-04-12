#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

  int ans = 1e9;

  // AB買わない
  ans = min(ans, A*X+B*Y);

  // ABだけ買う
  ans = min(ans, max(X, Y)*2*C);

  // ABとA,B買う
  ans = min(ans, X*2*C + max(0, (Y-X))*B);
  ans = min(ans, Y*2*C + max(0, (X-Y))*A);

  cout << ans << endl;
}