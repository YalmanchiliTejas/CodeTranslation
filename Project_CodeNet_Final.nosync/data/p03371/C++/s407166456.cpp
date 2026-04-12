#include <iostream>
#include <string>
using namespace std;

int main()
{
  int a,b,c,x,y;
  
  cin >> a >> b >> c >> x >> y;

  int ans=0;
  if (2*c < (a+b) )
  {
    if ( x>y)
    {
        ans=y*2*c+(x-y)*a;
    }
    else
    {
        ans=x*2*c+(y-x)*b;
    }
  }
  
  else
  {
      ans=a*x+b*y;
  }
  
  if (x>y)
  {
      int temp=x*c*2;
      if (temp<ans) ans=temp;
  }
  else
  {
      int temp=y*c*2;
      if (temp<ans) ans=temp;
  }
  
  cout << ans;

  return 0;
}
