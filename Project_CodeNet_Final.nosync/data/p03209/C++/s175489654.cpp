#include <algorithm>
#include <iostream>
#include <vector>

long long int solve(long long int n, long long int x,
                    std::vector<long long int> &a,
                    std::vector<long long int> &b) {
  if (x == 0) {
    return 0;
  } else if (x == 1) {
    return n == 0 ? 1 : 0;
  } else if (x < a[n - 1] + 2) {
    return solve(n - 1, x - 1, a, b);
  } else if (x == a[n - 1] + 2) {
    return b[n - 1] + 1;
  } else if (x <= 2 * a[n - 1] + 2) {
    return b[n - 1] + 1 + solve(n - 1, x - a[n - 1] - 2, a, b);
  } else {
    return b[n];
  }
}

int main() {
  long long int n, x;
  std::cin >> n >> x;
  std::vector<long long int> a(n + 1), b(n + 1);
  a[0] = 1, b[0] = 1;
  for (int i = 1; i < n + 1; i++) {
    a[i] = 3 + 2 * a[i - 1];
    b[i] = 1 + 2 * b[i - 1];
  }
  std::cout << solve(n, x, a, b) << std::endl;
}