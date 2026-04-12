#include <iostream>
using namespace std;

int main() {
  int x, y, z, ans;
  cin >> x >> y >> z;
  x -= z;
  ans = x / (y + z);
  cout << ans << endl;
}