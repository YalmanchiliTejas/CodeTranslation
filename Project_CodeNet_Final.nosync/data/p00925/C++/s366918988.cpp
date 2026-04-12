#include<iostream>
using namespace std;
string s;
int g(string s);
int f(string s)
{
	int ans=0,pre=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='+')
		{
			ans+=g(s.substr(pre,i-pre));
			pre=i+1;
		}
	}
	return ans;
}
int g(string s)
{
	int ans=1;
	for(int i=0;i<s.size();i++)ans*=s[i]=='*'?1:s[i]-'0';
	return ans;
}
main()
{
	cin>>s;
	int M=f(s+"+");
	int L=s[0]-'0';
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='+')L+=s[i+1]-'0';
		else if(s[i]=='*')L*=s[i+1]-'0';
	}
	int a;cin>>a;
	cout<<(a==M?a==L?"U":"M":a==L?"L":"I")<<endl;
}

