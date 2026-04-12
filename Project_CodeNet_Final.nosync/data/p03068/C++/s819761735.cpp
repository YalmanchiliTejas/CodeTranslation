
#include <bits/stdc++.h>

int main() {
  int64_t n, k;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::cin >> k;

  const char p = s[k - 1];

  for (auto &i : s) {
    if (i != p) {
      i = '*';
    }
  }

  std::cout << s << std::endl;
  return 0;
}
