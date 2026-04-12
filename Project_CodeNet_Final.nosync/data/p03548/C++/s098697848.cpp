#include<iostream>
using namespace std;
int main()
{
  int X,Y,Z;
  int i,j;
  cin>>X>>Y>>Z;
  i=Y+Z;
  for(j=0;i<=X-Z;j++)
    {
      i=Z+Y+i;
    }
  cout<<j<<endl;
  return 0;
}
  
