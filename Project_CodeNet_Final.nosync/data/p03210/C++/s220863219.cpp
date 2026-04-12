#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "cmath"
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[]) {
  ll NN;

  std::cin >> NN;

  int flag = 0;

  if (NN != 3) {
    if (NN != 5) {
      if (NN != 7) {
        flag = 1;
      }
    }
  }


  if (flag == 0) {
    std::cout << "YES" << '\n';
  }else{
    std::cout << "NO" << '\n';
  }


  return 0;
}
