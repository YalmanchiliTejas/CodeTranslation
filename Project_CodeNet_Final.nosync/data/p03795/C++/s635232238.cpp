#include <iostream>

int main() {

  int N;

  std::cin >> N;

  int sumMoney;
  int serviceCount;

  serviceCount = int(N / 15);

  sumMoney = N * 800 - serviceCount * 200;

  std::cout << sumMoney << std::endl;
  return 0;
}