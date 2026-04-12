#include <iostream>
using namespace std;
int main()
{
  int n, m, h;
  cin >> n;
  cin >> m;
  int c = 1;
  for (int i = 1; i < n; i++) {
    cin >> h;
    if (m <= h) {
      m = h;
      c++;
    }
  }
  cout << c << endl;
  return 0;
}