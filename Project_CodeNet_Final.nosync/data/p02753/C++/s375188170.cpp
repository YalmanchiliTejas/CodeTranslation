#include <iostream>
#include <string>

int main() {
  std::string list;

  std::cin >> list;

  if ((list.c_str()[0] == list.c_str()[1]) && (list.c_str()[1] == list.c_str()[2])) {
    std::cout << "No" << std::endl;
  } else {
    std::cout << "Yes" << std::endl;
  }

  return 0;
}