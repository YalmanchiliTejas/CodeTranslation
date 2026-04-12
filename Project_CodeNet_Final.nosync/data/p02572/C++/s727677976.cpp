#include <iostream>

using std::cin;
using std::cout;

int n, i;
long long v, s, a;
const long long m = 1e9 + 7;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 0; i != n; ++i) {
    cin >> v;
    a = (a + v * s) % m;
    s = (s + v) % m;
  }
  cout << a;
  return 0;
}
