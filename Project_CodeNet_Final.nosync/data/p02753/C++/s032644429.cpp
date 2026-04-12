#include<bits/stdc++.h>
using namespace std;
  int main()
{
  char s[4];
  cin>>s;
  int i,flag=1;
  char c=s[0];
  for(i=0;i<3;++i)
  {	if(s[i]!=c)
    {
      flag=0;
      break;
    }
}
  if(flag==1)
    cout<<"No";
  else
    cout<<"Yes";
  return 0;
}