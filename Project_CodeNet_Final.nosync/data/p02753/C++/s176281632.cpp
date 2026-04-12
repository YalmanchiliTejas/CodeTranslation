#include<bits/stdc++.h>
using namespace std;
string s;
bool ok1,ok2;
int main()
{
	cin>>s;
	if(s[0]=='A')
	{
		ok1=true;
	}
	else
	{
		ok2=true;
	}
	if(s[1]=='A')
	{
		ok1=true;
	}
	else
	{
		ok2=true;
	}
	if(s[2]=='A')
	{
		ok1=true;
	}
	else
	{
		ok2=true;
	}
	if(ok1 && ok2)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}