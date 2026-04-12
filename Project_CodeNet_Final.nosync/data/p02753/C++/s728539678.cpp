#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  string s1("AAA");
  string s2("BBB");
  if(s.compare(s1)==0 || s.compare(s2)==0)
    cout<<"No";
  else
    cout<<"Yes";
  return 0;
}