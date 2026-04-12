#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int x, y, z;
  cin >> x >> y >> z;

  int ans = 0;
  x -= z;
  while (x > 0) {
    if (x - (y+z) >= 0) ans++;
    x -= (y+z);
  }
  cout << ans << endl;
  return 0;
}
