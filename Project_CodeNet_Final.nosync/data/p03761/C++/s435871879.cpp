#include <bits/stdc++.h>

using namespace std;

std::string solve(const std::vector<std::string>& ss) {
  std::array<int, 26> intersectCounts{};
  for (auto& count : intersectCounts) {
    count = INT_MAX;
  }

  for (const auto& s : ss) {
    std::array<int, 26> counts{};
    for (auto const c : s) {
      counts[c - 'a']++;
    }
    for (int i = 0; i < intersectCounts.size(); i++) {
      intersectCounts[i] = std::min(counts[i], intersectCounts[i]);
    }
  }
  std::string ret;
  for (int i = 0; i < intersectCounts.size(); i++) {
    auto count = intersectCounts[i];
    while (count--) {
      ret += ('a' + i);
    }
  }
  return ret;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> ss(n);
  for (auto& s : ss) {
    std::cin >> s;
  }
  std::cout << solve(ss) << std::endl;
  return 0;
}
