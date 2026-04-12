#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  int ca=0,cb=0;
  char ch;
  cin>>s;
  int l=s.length();
  for(int i=0;i<l;i++)
  {
    ch=s.at(i);
    if(ch=='A')
      ca++;
    else
      cb++;
  }
  if(ca==3||cb==3)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}
