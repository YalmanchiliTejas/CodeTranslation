#include<iostream>
using namespace std;
int x,y,z,ans;
int main()
{
  cin>>x>>y>>z;
  x-=z;
  while(1)
  {
    if(x<y+z){cout<<ans<<endl;return 0;}
    x-=y+z,++ans;
  }
}