#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = C * (max(X, Y) * 2);
  if(X > Y) {
  for(int i = 0; i <= Y; i++) {
    ans = min(ans, (i * B) + (A * (i+(X-Y))) + C*2*(Y-i));
  }
  }
  else {
    for(int i = 0; i <= X; i++) {
    ans = min(ans, (i * A) + (B * (i+(Y-X))) + C*2*(X-i));
  }
  }
  cout << ans;
}