#include <iostream>
#include <string>

int main()
{
  int n, k;
  std::string s;
  std::cin >> n;
  std::cin >> s;
  std::cin >> k;
  char target = s.at(k-1);
  for (auto& c : s) {
    if (c != target) {
      c = '*';
    }
  }
  std::cout << s << '\n';
  return 0;
}
