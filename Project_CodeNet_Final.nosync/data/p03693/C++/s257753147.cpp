#include<iostream>
using namespace std;
int main()
{
  int r,g,b;
  cin>>r>>g>>b;
  int i=100*r+10*g+b;
  if(i%4==0)
    {
      cout<<"YES"<<endl;
    }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
