#include<iostream>
#include<string>
using namespace std;
string s;

int main()
{
  cin>>s;
  int flag=0;
  if(s[0]==s[1]&&s[1]==s[2])cout<<"No";
  else cout<<"Yes";
  return 0;
}