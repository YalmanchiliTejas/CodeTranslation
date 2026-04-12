#include <iostream>
using namespace std;
int main()
{
  int x,y,z;cin >> x >> y >> z;
  if((x*100+y*10+z)%4)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}