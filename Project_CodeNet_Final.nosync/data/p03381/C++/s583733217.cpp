#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int solve(const std::vector<int>& xs, int remove) {
  int mid = xs.size() / 2;
  int s = xs[mid - 1];
  int l = xs[mid];
  return (remove <= s ? l : s);
}

int main() {
  int N;
  std::cin >> N;
  std::vector<int> xs;
  for (int i = 0; i < N; ++i) {
    int x;
    std::cin >> x;
    xs.push_back(x);
  }
  std::vector<int> xss = xs;
  std::sort(xss.begin(), xss.end());
  for (int i = 0; i < N; ++i) {
    std::cout << solve(xss, xs[i]) << std::endl;
  }
}
