#include <bits/stdc++.h>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> a(h);

  for (int i = 0; i < h; i++) {
    std::cin >> a[i];
  }

  const auto end_itr = std::remove_if(a.begin(), a.end(),
    [](const auto &i){
      return std::all_of(i.cbegin(), i.cend(),
        [](const auto c){return c == '.';});});
  std::set<int> remove;
  for (size_t i = 0; i < a[0].size(); i++) {
    bool flag = true;
      for (auto itr = a.begin(); itr != end_itr; itr++) {
      if (itr->at(i) != '.') {
        flag = false;
      }
    }
    if (flag) {
      remove.insert(i);
    }
  }

  for (auto itr = a.begin(); itr != end_itr; itr++) {
    for (int j = 0; j < a[0].size(); j++) {
      if (remove.find(j) == remove.cend()) {
        std::cout << itr->at(j);
      }
    }
    std::cout <<std::endl;
  }
  return 0;
}