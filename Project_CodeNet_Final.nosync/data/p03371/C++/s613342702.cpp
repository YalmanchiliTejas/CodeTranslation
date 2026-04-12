#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int ans = 2000000000;
  for (int a = 0; a < X + 1; ++a) {
    int c = (X - a) * 2;
    int b = max(0, Y - c / 2);
    ans = min(ans, A * a + B * b + C * c);
  }
  for (int b = 0; b < Y + 1; ++b) {
    int c = (Y - b) * 2;
    int a = max(0, X - c / 2);
    ans = min(ans, A * a + B * b + C * c);
  }
  
  cout << ans << endl;
  return 0;
}