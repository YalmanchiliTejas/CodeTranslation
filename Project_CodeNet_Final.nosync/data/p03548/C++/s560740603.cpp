#include "bits/stdc++.h"
using namespace std;
#define dump(x) cout << (x) << endl;
typedef int64_t Int;
Int mod = 1e9+7;

int main() {
  Int x, y, z;
  cin >> x >> y >> z;
  Int res = (x - z) / (y + z);
  x %= (y + z);
  if (x >= y + z) res++;
  dump(res);
  return 0;
}
