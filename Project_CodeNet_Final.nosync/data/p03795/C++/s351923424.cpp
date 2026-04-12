#include <iostream>

using namespace std;

int main(void)
{
  int N;
  int x,y;
  cin >> N;

  x = 800 * N;
  y = N/15 * 200;

  cout << x - y << endl;
  
  return 0;
}
