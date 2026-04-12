#include <iostream>
#include <string>

int main() {
  std::string str;
  std::cin >> str;
  int N = std::stoi(str);

  if (N >= 30) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }

  return 0;
}