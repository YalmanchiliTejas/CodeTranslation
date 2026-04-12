#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int vmax = -1;
  while (n--) {
    int h;
    cin >> h;
    if (vmax <= h) {
      ++ans;
      vmax = h;
    }
  }
  cout << ans << endl;
}