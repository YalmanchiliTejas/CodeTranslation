#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  string s;
  cin >> s;
  bool result = false;
  for (int i = 0; i + 1 < (int)s.size(); ++i)
    if (s[i] == 'A' && s[i + 1] == 'C') {
      result = true;
      break;
    }
  if (result) printf("Yes\n");
  else printf("No\n");
  return 0;
}
