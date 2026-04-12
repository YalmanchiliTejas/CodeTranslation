#include <iostream>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int sum = 0, r, g, b;
  cin >> r >> g >> b;
  sum += 100 * r;
  sum += 10 * g;
  sum +=  b;
  if (sum % 4 == 0) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
