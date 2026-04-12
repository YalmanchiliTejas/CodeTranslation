#include<bits/stdc++.h>                                                         
using namespace std;
int main()
{
  int X,Y,Z;
  cin >> X >> Y >> Z;
  X=X-(Y+2*Z);
  int count=1;
  while(1){
    if(X>=Y+Z){
      count++;
      X-=(Y+Z);
    }
    else
      break;
  }
  cout << count << endl;
}