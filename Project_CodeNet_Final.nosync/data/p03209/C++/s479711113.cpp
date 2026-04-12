#include <bits/stdc++.h>

int main() {
  std::array<uint64_t, 51> num;
  std::array<uint64_t, 51> p;
  num[0] = 1;
  p[0] = 1;
  for (int i = 0; i < 50; i++) {
    num[i + 1] = 2 * num[i] + 3;
    p[i + 1] = 2 * p[i] + 1;
  }

  uint64_t n, x;
  std::cin >> n >> x;
  uint64_t eat = 0;

  while (n != 0) {
    if (x == num[n]) {
      x -= num[n];
      eat += p[n];
    } else if (x == num[n] - 1) {
      x -= num[n] - 1;
      eat += p[n];
    } else if (2 + num[n - 1] < x && x < num[n] - 1) {
      x -= 2 + num[n - 1];
      eat += 1 + p[n - 1];
    } else if (x == 2 + num[n - 1]) {
      x -= 2 + num[n - 1];
      eat += 1 + p[n - 1];
    } else if (x == 1 + num[n - 1]) {
      x -= 1 + num[n - 1];
      eat += p[n - 1];
    } else if (1 < x && x <= num[n - 1]) {
      x -= 1;
    } else if (x == 1) {
      x -= 1;
    } else {
    }
    n--;
  }
  if (x == 1) {
    eat++;
  }

  std::cout << eat << std::endl;
  return 0;
}
