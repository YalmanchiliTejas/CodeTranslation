#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
int main() {
  int A, B, C, X, Y, Z = 0, total = 0;
  cin >> A >> B >> C >> X >> Y;
  if (A + B < 2 * C) { // AピザとBピザを別々の方が安い
    total = X * A + Y * B;
  } else { // ABピザの方が安い
    Z = min(X, Y);
    total = 2 * C * Z;
    int restX = max(0, X - Z);
    int restY = max(0, Y - Z);
    if (restX > 0) {
      if (A < 2 * C) { // Aピザを別に買った方が安い
        total += A * restX;
      } else { // ABピザの方が安い
        total += 2 * C * restX;
      }
    }
    if (restY > 0) {
      if (B < 2 * C) {
        total += B * restY;
      } else {
        total += 2 * C * restY; 
      }
    }
  }
  cout << total << endl;
  return 0;
}