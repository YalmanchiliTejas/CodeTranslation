#include <iostream>

using namespace std;

int main()	{
  int r, g, b;
  cin >> r >> g >> b;
  if ((b + g*10) % 4 == 0)	
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}