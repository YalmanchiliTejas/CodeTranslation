#include <bits/stdc++.h>

using namespace std;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int x;
  std::cin >> x;
  if (x == 3 || x == 5 || x == 7) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}
