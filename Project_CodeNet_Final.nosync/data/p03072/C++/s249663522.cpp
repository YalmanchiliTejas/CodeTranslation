#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
typedef long long LL;

int main() {
  int N; std::cin >> N;

  int cnt = 0;
  int height = 0;
  for (int i = 0; i < N; ++i) {
    int h; std::cin >> h;
    if (height <= h) {
      ++cnt;
      height = h;
    }
  }

  std::cout << cnt << std::endl;
}
