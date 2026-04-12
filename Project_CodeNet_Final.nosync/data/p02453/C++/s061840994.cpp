#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  long a[100001];
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  int q;
  std::cin >> q;

  for (int i = 0; i < q; ++i) {
    long k;
    std::cin >> k;
    std::cout << std::lower_bound(a, a + n, k) - a << std::endl;
  }
}

