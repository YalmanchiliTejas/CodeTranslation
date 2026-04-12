#include <iostream>
int main() {
  int age;
  std::cin >> age;
  if (age == 3 || age == 5 || age == 7) std::cout << "YES";
  else std::cout << "NO";
}
