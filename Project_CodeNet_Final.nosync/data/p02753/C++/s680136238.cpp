#include<bits/stdc++.h>
using namespace std;
string station(string s)
{
  int a=0,b=0;
  string res;
  for(int i=0;i<3;i++)
  {
    if(s[i]=='A')
      a++;
    else
      b++;
  }
  if(a==3||b==3)
    res="No";
  else
    res="Yes";
  return res;
}
int main()
{
  string s,res;
  getline(cin,s);
  res=station(s);
  cout<<res;
  return 0;
}