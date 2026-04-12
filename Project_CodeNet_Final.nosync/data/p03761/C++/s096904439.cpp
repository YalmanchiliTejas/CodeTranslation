#include<bits/stdc++.h>
using namespace std;
int n,d[30];
string ans;
int main()
{
	cin>>n;
	for(int i=0;i<26;i++)
	{
		d[i]=1e9;
	}
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int cnt[26];
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<s.size();j++)
		{
			cnt[s[j]-'a']++;
		}
		for(int j=0;j<26;j++)
		{
			d[j]=min(d[j],cnt[j]);
		}
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<d[i];j++)
		{
			ans+=(char)('a'+i);
		}
	}
	cout<<ans<<endl;
	return 0;
}