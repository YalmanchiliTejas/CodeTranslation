#include <iostream>
#include <cstdint>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>

int main() {
  std::int_fast64_t n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::multiset<char> multiset(s.begin(), s.end());
  for (std::int_fast64_t i = 1; i < n; ++i) {
    std::cin >> s;
    std::multiset<char> prev_multiset = std::move(multiset);
    std::multiset<char> curr_multiset(s.begin(), s.end());
    std::set_intersection(prev_multiset.begin(), prev_multiset.end(), curr_multiset.begin(), curr_multiset.end(), std::inserter(multiset, multiset.end()));
  }
  std::cout << std::string(multiset.begin(), multiset.end()) << std::endl;
  return 0;
}