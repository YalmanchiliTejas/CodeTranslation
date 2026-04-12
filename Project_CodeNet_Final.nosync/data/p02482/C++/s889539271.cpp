#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int x,y;
  while(cin>>x>>y)
  {
     if(x>y){cout<<"a > b"<<endl;}
     if(x<y){cout<<"a < b"<<endl;}
     if(x==y){cout<<"a == b"<<endl;}
    }
    return 0;
}