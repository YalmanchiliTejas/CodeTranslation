#include <iostream>
int main(int argc, char *argv[]) {
  int r, g, b;
  bool yes = false;
  std::cin >> r >> g >> b;
  if ((r * 100 + g * 10 + b) % 4 == 0)
    yes = true;
  std::cout << (yes ? "YES" : "NO") << std::endl;
}
