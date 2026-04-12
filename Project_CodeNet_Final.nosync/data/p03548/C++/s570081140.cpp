#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std; 
int main(int argc,char const* argv[])
{
  int x,y,z;
  int ans=0;
  cin >> x >> y >> z;
  x=x-(2*z)-y;
  ans++;
  while(x>=(y+z))
    {
      x=x-y-z;
      ans++;
    }
  cout << ans << endl;
  return 0;
}