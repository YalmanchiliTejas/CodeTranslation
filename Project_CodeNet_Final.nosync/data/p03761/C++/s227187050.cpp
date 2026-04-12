#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int n,t[55][26]={};
	string s,ans="";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			t[i][s[j]-'a']++;
		}
		for(int j=0;j<26;j++)
		{
			if(i)t[i][j]=min(t[i][j],t[i-1][j]);
		}
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<t[n-1][i];j++)
		{
			ans+='a'+i;
		}
	}
	cout<<ans<<endl;
	return 0;
}