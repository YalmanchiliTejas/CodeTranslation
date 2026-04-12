#include <iostream>
#include <algorithm>

using namespace std;

int const nmax = 100;
int v[1 + nmax];

int main() {

  int n, m, sum = 0, p, mint = 1000000;
  cin >> n >> m >> p;
  cout << (n - p) / (m + p);
  return 0;
}
