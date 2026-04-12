#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;



int main(int argc, char* argv[])
{
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x;
  cin >> x;
  if (x == 7 || x == 5 || x == 3) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
