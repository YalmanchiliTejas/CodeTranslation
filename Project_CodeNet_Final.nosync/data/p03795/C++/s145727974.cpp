#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int pay;
  int comeback;
  int result;

  std::cin >> n;

  pay = 800 * n;
  comeback = (n / 15) * 200;
  result = pay - comeback;

  std::cout << result << '\n';
  return 0;
}
