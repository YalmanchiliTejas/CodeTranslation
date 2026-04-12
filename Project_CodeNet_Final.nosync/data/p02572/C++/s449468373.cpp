#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int n, i;
vector<long long> a;
long long v, s, z;
const long long m = 1e9 + 7;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a.reserve(n);
  for (i = 0; i != n; ++i) {
    cin >> v;
    s += v;
    a.push_back(v);
  }
  for (long long v : a) {
    z = (z + v * ((s - v) % m)) % m;
  }
  if (z & 1)
    z = (z + m) / 2 % m;
  else
    z /= 2;
  cout << z;
  return 0;
}
