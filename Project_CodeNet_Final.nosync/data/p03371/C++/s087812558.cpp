#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  if (A > B) {
    swap(A, B);
    swap(X, Y);
  }
  int ans = 0;
  if (A + B >= C * 2) {
    int z = min(X, Y);
    ans += C * 2 * z;
    X -= z;
    Y -= z;
  }
  if (B < C * 2) 
    ans += A * X + B * Y;
  else if (A < C * 2)
    ans += C * 2 * Y + A * max(0, X - Y);
  else
    ans += C * 2 * max(X, Y);
  cout << ans << "\n";
}