#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	vector<int> h(26);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		vector<int> tmp(26);
		cin>>s;
		for(auto j:s)tmp[j-'a']++;
		if(i==0)
		{
			for(auto j:s)h[j-'a']++;
		}
		for(int j=0;j<26;j++)
		h[j]=min(h[j],tmp[j]);
		
	}
	string ans="";
	for(int i=0;i<26;i++)
	{
		ans+=string(h[i],i+'a');
	}
	cout<<ans;
} 