#include<bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  cin>>str;
  set<char>s;
  for(int i=0;i<3;i++)
  {
    s.insert(str[i]);
  }
  if(s.size()==2)
  {
    cout<<"Yes\n";
  }
  else
  {
    cout<<"No\n";
  }
}