#include <iostream>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++ )

int main()
{
  int n;
  cin >> n;
  int y = n / 15;
  cout << 800 * n - (y * 200) << endl;
}
