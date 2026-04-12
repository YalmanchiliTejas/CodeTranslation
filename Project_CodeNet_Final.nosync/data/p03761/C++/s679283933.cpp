#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int ans[27],t[27];
int main()
{
	string s;
	int n;
	cin>>n;
	memset(ans,0x3f,sizeof(ans));
	while(n--)
	{
		cin>>s;
		memset(t,0,sizeof(t));
		for(int i=0;i<s.length();i++)
		t[s[i]-'a'+1]++;
		for(int i=1;i<=26;i++)
		if(t[i]<ans[i]) ans[i]=t[i];
	}
	for(int i=1;i<=26;i++)
	for(int j=0;j<ans[i];j++)
	cout<<(char)('a'+i-1);
	return 0;
}