#include<iostream>
#include<string>
using namespace std;
int main()
{
  int r,g,b;
  int a;

  cin>>r>>g>>b;
  a=r*100+g*10+b;
  if(a%4==0)
  {
    cout<<"YES";
  }
  else
  {
    cout<<"NO";
  }
  cout<<endl;
}
