#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;

  std::vector<int> h;

  for (size_t i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    h.push_back(tmp);
  }

  bool is_ok = true;
  bool is_checked = false;
  int count = 1;
  
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < i; j++) {
      is_checked = true;
      if (h.at(i) < h.at(j)) {
        is_ok = false;
        break;
      }
    }

    if (is_ok == true && is_checked == true) {
      count++;
    }

    is_ok = true;
    is_checked = false;
  }
  
  std::cout << count << '\n';
  return 0;
}