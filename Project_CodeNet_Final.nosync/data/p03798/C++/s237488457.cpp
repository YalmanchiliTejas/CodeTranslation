#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <array>

char next_animal(const char prev_animal, const char curr_animal, const char answer) {
  static std::array<char, 8> pattern = {'S', 'W', 'W', 'S', 'W', 'S', 'S', 'W'};
  return pattern[(prev_animal == 'W' ? 4 : 0) | (curr_animal == 'W' ? 2 : 0) | (answer == 'x' ? 1 : 0)];
}

int main() {
  std::int_fast64_t n;
  std::string s;
  std::cin >> n >> s;

  std::vector<std::vector<char>> possible_patterns(4);
  possible_patterns[0].push_back('S');
  possible_patterns[0].push_back('S');
  possible_patterns[1].push_back('S');
  possible_patterns[1].push_back('W');
  possible_patterns[2].push_back('W');
  possible_patterns[2].push_back('S');
  possible_patterns[3].push_back('W');
  possible_patterns[3].push_back('W');
  for (std::vector<char>& possible_pattern : possible_patterns) {
    for (const char& answer : s) {
      possible_pattern.push_back(next_animal(*(possible_pattern.rbegin() + 1), possible_pattern.back(), answer));
    }
    if (possible_pattern.front() == *(possible_pattern.rbegin() + 1) && *(possible_pattern.begin() + 1) == possible_pattern.back()) {
      std::cout << std::string(possible_pattern.begin() + 1, possible_pattern.end() - 1) << std::endl;
      return 0;
    }
  }
  std::cout << -1 << std::endl;
  return 0;
}