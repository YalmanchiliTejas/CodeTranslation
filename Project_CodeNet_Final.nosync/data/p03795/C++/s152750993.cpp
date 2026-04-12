#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int w = (n / 15) * 200;
  n *= 800;
  cout << n - w << '\n';
  return 0;
}