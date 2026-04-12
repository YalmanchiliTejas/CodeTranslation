#include<iostream>

int main(int argc, char const *argv[]) {
  int num;
  std::cin >> num;
  int y = num / 15;
  std::cout << num * 800 - 200 * y << std::endl;
  return 0;
}
