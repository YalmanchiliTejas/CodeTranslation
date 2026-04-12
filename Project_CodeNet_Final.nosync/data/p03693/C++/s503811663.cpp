#include <iostream>
using namespace std;

int main()
{
  int _, g, b;
  cin >> _ >> g >> b;
  if ((g * 10 + b) % 4 == 0)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }  

  return 0;
}
