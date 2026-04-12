#include<iostream>
using namespace std;

int main()
{
  char s[3];
  char judge;
  int count=0;
  for(int i=0;i<3;i++)
  {
    cin>>s[i];
    judge=s[0];
    if(judge==s[i])
    {
      count++;
    }
  }
  if(count==3)
  {
    cout<<"No";
  }
  else
  {
    cout<<"Yes";
  }
}
