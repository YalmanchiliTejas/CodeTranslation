#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  int n;
  std::cin >> n;
  std::vector<std::string> v(n);

  for (int i = 0; i < v.size(); i++) {
    std::cin >> v[i];
    std::sort(v[i].begin(), v[i].end());
  }

  std::string out;
  std::vector<int> char_cnt(n);
  for(char c : alphabet) {
    for (int i = 0; i < char_cnt.size(); i++) {
      char_cnt[i] = std::count(v[i].begin(), v[i].end(), c);
    }
    int min = *std::min_element(char_cnt.begin(), char_cnt.end());
    if (min) {
      for (int i = 0; i < min; i++) {
        out += c;
      }
    }
  }
  if (out.size() != 0) {
    std::cout << out;
  } else {
    std::cout << std::endl;
  }

  return 0;
}