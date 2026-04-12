#include<bits/stdc++.h>
using namespace std;
int main()
{
  
 	string s;
  cin>>s;
  	int cb=0;
  int ca=0;
  for(int i=0 ;i < 3;i++)
    	if(s[i]=='A')ca++;
  		else cb++;
  
  if(ca>0 && cb>0)
    	cout<<"Yes\n";
  else	
    cout<<"No\n";
}