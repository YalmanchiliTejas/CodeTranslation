#include <iostream>
using namespace std;
int main( void )
{
  ios::sync_with_stdio(false);
  int r, g, b;
  cin >> r >> g >> b;
  if( (r*100 + g*10 + b) % 4 == 0 )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}