#include<iostream>
using namespace std;
int main()
{
  char s[3];
  int a=0,b=0;
  cin>>s;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A'||s[i]=='a')
      a++;
    else if(s[i]=='B'||s[i]=='b')
      b++;
  }
  if(a==2 || b==2)
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}
