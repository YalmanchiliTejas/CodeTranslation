#include <string>
#include <iostream>

int main() {
 std::string s;
  std::cin >> s;
  if (s == "AAA" || s == "BBB")
    std::cout << "No\n";
  else
    std::cout << "Yes\n";
}