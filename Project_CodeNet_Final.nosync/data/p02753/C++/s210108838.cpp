#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  int a=s.size();
  cin>>s;
	if(s[0]=='A'&&s[1]=='A'&&s[2]=='A'||s[0]=='B'&&s[1]=='B'&&s[2]=='B')
    cout<<"No";
  else 
     cout<<"Yes";
  return 0;
}