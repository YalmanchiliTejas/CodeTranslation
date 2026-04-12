#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  
  int ca=0,cb=0;
  for(int i=0;i<s.size();i++)
  {
	if(s[i]=='A')
    {
    	ca++;
    }
    else
    {
      cb++;
    }
  }
  
  if(ca==s.size() || cb==s.size())
  {
	cout<<"No"<<endl;
  }
  
  else{
    cout<<"Yes"<<endl;
  }
  return 0;
}
      