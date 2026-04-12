#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;

  std::cout << n*800-(n/15)*200 << endl;
  return 0;
}
