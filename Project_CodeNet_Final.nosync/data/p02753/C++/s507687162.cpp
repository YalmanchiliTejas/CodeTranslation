#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		{
			a++;
		}
		else
		{
			b++;
		}
	}
	if((a==1&&b==2)||(a==2&&b==1))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}