#include <iostream>
#include <vector>

int main() {
  size_t N;
  std::cin >> N;

  std::vector<int32_t> v;
  for (size_t i = 0; i < N; i++) {
    int32_t n;
    std::cin >> n;
    v.emplace_back(n);
  }

  int32_t highest = v[0];
  int32_t result = 0;
  for (const auto& h : v) {
    if (highest <= h) {
      result++;
      highest = h;
    }
  }

  std::cout << result << std::endl;

  return 0;
}