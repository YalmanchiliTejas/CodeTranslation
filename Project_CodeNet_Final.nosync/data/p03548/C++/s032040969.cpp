#include<iostream>
using namespace std;
int main()
{
  int x,y,z;
  cin>>x>>y>>z;
  int a=x/(y+z);
  if(x-a*(y+z)<z){
    cout<<a-1;
  }
  else{
    cout<<a;
  }
}