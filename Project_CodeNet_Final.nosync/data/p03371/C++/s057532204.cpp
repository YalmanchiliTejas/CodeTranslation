#include <iostream>
#include <string>

using namespace std;

int main()
{
  int a,b,ab;
  int x,y;
  int sum = 0;

  cin >> a >> b >> ab >> x >> y;

  if ( a+b < ab*2 )
  {
    sum += x*a+y*b;
  } else {
    if ( x > y ) {
      sum += ab*2*y;
      sum += min(ab*2*(x-y), a*(x-y));
    } else {
      sum += ab*2*x;
      sum += min(ab*2*(y-x), b*(y-x));
    }
  }

  cout << sum << endl;
}
