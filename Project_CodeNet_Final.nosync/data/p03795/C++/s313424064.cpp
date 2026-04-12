#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  const auto x = 800 * n;
  const int y = 200 * (n / 15);
  cout << x - y << endl;

  return 0;
}
