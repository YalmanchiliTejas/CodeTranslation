#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
#ifdef _75108D01685041AA959399A981476AD7
  std::freopen("input.txt", "r", stdin);
#endif

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  int msf = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    res += (x >= msf);
    msf = max(msf, x);
  }

  cout << res << endl;

  return 0;
}