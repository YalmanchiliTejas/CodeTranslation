#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int a, b, c;
  int x, y;
  int ans = 0;

  cin >> a >> b >> c >> x >> y;
  c *= 2;

  if ( a + b > c ) {
    ans += min(x, y) * c;
    if ( x <= y ) {
      y -= x;
      x = 0;
    } else {
      x -= y;
      y = 0;
    }
  }

  if ( a > b ) {
    ans += x * min(a, c);
    x = 0;
    if ( c <= a ) {
     y -= x;
     if ( y < 0 ) {
       y = 0;
     }
    }
    ans += y * min(b, c); 
  } else {
    ans += y * min(b, c);
    y = 0;
    if ( c <= b ) {
      x -= y;
      if ( x < 0 ) {
        x = 0;
      }
    }
    ans += x * min(a, c);
  }

  cout << ans << endl;

  return (0);
}
