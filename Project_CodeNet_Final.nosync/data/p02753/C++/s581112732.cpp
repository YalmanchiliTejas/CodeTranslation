#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  char station_list[3];
  for(int i = 0; i < 3; i++) {
    std::cin >> station_list[i];
  }
  if(station_list[0] == station_list[1] && station_list[1] == station_list[2]) {
    std::cout << "No";
  }
  else {
    std::cout << "Yes";
  }
  return 0;
}