#include <iostream>
using namespace std;

int main() {
  int64_t n, x;
  cin >> n >> x;
  int64_t p[n + 1], size[n + 1], result = 0;
  p[0] = 1;
  size[0] = 1;
  for (int64_t i = 1; i <= n; ++i) {
    p[i] = 2 * p[i - 1] + 1;
    size[i] = 2 * size[i - 1] + 3;
  }
  for (int64_t i = n; i >= 0; --i) {
    if (x == 0) {
      break;
    }
    if (x == size[i]) {
      result += p[i];
      break;
    }
    if (x == 1) {
      break;
    }
    if (x <= 1 + size[i - 1]) {
      --x;
    } else {
      result += 1 + p[i - 1];
      x -= 2 + size[i - 1];
    }
  }
  cout << result;
  return 0;
}