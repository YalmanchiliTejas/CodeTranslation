#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>

class Hamburger {
  public:
    long long size;
    long long point;
};

int main()
{
  long long level, x;
  std::cin >> level >> x;
  std::vector<Hamburger> hamburger(level);
  hamburger.at(0).size  = 1;
  hamburger.at(0).point = 1;
  for (int i = 1; i < (int)hamburger.size(); i++) {
    hamburger.at(i).size = hamburger.at(i-1).size * 2 + 3;
    hamburger.at(i).point = hamburger.at(i-1).point * 2 + 1;
  }
  long long total_point = 0;
  long long rest = x;
  for (auto it = hamburger.rbegin(); it != hamburger.rend(); it++) {
    long long size = it->size;
    long long point = it->point;
    if (1 == rest) {
      break;
    } else if (1 < rest && rest <= size+1) {
      rest -= 1;
      if (size == 1) {
        total_point++;
        break;
      }
      continue;
    } else if (size+2 == rest) {
      total_point += point + 1;
      break;
    } else if (size+2 < rest && rest <= 2*size+2) {
      total_point += point + 1;
      rest -= size + 2;
      if (size == 1) {
        total_point++;
        break;
      }
      continue;
    } else if (2*size+3 == rest) {
      total_point += 2 * point + 1;
      break;
    } else {
      std::cerr << "Unexpected rest\n";
      exit(1);
    }
  }
  std::cout << total_point << std::endl;
  return 0;
}
