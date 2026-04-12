#include <bits/stdc++.h>
using namespace std;

int A;
int B;
int C;
int X;
int Y;
int ans;

void solve() {
  if (X > Y) {
    ans = min(A*Y+B*Y, 2*C*Y) + min(A*(X-Y), 2*C*(X-Y));
  } else {
    ans = min(A*X+B*X, 2*C*X) + min(B*(Y-X), 2*C*(Y-X));
  }
  cout << ans << endl;
}

int main() {
  cin >> A >> B >> C >> X >> Y;
  solve();
}