#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  cin >> n;
  cout << n * 800 - (n/15) * 200 << endl;
}