#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long int cnt = 0, out = 100000000000000;
  int i = 0, j = 0;
  int base = max(x, y);
  for (int k = 0; k <= base*2; k += 2) {
    i = x - k / 2;
    j = y - k / 2;
    if (i < 0) i = 0;
    if (j < 0) j = 0;
    cnt = i * a + j * b + k * c;
    out = min(out, cnt);
  }
  cout << out << endl;
  return 0;
}
