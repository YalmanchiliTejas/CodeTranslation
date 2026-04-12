#include <iostream>
using namespace std;


int main()
{
  int x, y, z;

  cin >> x >> y >> z;
  x -= 2*z;
  
  int i=0, cnt=0;
  while ( 1 ) {
    if ( i%2 == 0 ) {
      x -= y;
      if ( x < 0 ) break;
      cnt++;
    } else {
      x -= z;
      if (x < 0 ) break;
    }
    i++;
  }
  cout << cnt << endl;
    
  return 0;
}
