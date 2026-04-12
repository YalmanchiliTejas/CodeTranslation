#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int a=0;
  int b=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='A')
       a++;
    else
      b++;
  }
  if(a>0 &&b>0)
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}
