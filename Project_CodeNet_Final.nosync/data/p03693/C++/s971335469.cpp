#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  std::cin >> a>>b>>c;
  int d=10*b +c;
  if (d%4==0) {
    std::cout << "YES" << '\n';/* code */
  }
  else{
    std::cout << "NO" << '\n';
  }
}
