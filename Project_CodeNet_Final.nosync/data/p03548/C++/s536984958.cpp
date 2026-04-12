#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int X, Y, Z;
  cin >> X >> Y >> Z;

  const int ans = (X - Z) / (Z + Y);
  cout << ans << endl;

  return 0;
}