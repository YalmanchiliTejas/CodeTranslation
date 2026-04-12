#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> h.at(i);
  }
  int count = 0;
  int max_h = 0;
  for (size_t i = 0; i < n; i++) {
    if (h.at(i) >= max_h) {
      /* code */
      count++;
      max_h = h.at(i);
    }
  }
  std::cout << count << '\n';
}