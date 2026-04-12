#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>

using namespace std;

inline int64_t num_layers(int64_t n) {
  return pow(2, n+2) - 3;
}

inline int64_t num_putties(int64_t n) {
  return pow(2, n+1) - 1;
}

int64_t countup_putties(int64_t n, int64_t x) {
  if (n == 0) return 1;
  int64_t child_nl = num_layers(n-1);
  int64_t child_np = num_putties(n-1);
  if (x == 1) {
    return 0;
  } else if (x <= child_nl + 1) {
    return countup_putties(n-1, x-1);
  } else if (x == child_nl + 2) {
    return child_np + 1;
  } else {
    return child_np + 1 + countup_putties(n-1, x-child_nl-2);
  }
}

int main() {
  int64_t n, x;
  cin >> n >> x;
  cout << countup_putties(n, x) << endl;
  return 0;
}
