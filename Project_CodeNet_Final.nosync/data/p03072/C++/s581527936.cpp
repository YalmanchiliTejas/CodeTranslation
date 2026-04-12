#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  int max_height = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int height;
    std::cin >> height;
    if (max_height <= height) {
      cnt++;
      max_height = height;
    }
  }
  std::cout << cnt << '\n';
  return 0;
}
