#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int b = n / 15 * 200;
  int ans = 800 * n - b;
  cout << ans << endl;
  return 0;
}
