#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>cnt(26,1e9);
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		vector<int>v(26);
		for(int j=0;j<s.size();j++)
		v[s[j]-'a']++;
		for(int j=0;j<26;j++)
		cnt[j]=min(cnt[j],v[j]);
	}
	for(int i=0;i<26;i++)
	cout<<string(cnt[i],i+'a');
	cout<<endl;
	return 0;
}