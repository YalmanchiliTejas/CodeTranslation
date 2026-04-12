#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{
  char a;
  int c=0,d=0;
  for(int i=0;i<3;i++)
  {
    cin>>a;
    if(a=='A')
      c++;
    else
      d++;
  }
  if(c!=0&&d!=0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}