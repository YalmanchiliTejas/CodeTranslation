#include<iostream>
using namespace std;
int x,y,z,cnt=1;
int main()
{
  cin>>x>>y>>z;
  x=x-y-z*2;
  while(x>0)
  {
    x=x-y-z;
    if(x>=0)cnt++;
  }
  cout<<cnt<<endl;
}