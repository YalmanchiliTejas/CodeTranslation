#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
  int r, g, b;
  cin >> r >> g >> b;

  int a = 100 * r + 10 * g + b;
  cout << (a % 4 == 0 ? "YES" : "NO") << endl;
  
  return 0;
}
