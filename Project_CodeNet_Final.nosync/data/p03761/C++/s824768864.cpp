#include<bits/stdc++.h>
using namespace std;
string s[50];
vector<int> cnt(26,1e9);
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		vector<int> v(26,0);
		for(int j=0;j<s[i].size();j++)
		v[s[i][j]-'a']++;
		for(int j=0;j<26;j++)
		cnt[j]=min(cnt[j],v[j]);
	}
	for(int i=0;i<26;i++)
	cout<<string(cnt[i],i+'a');
	return 0;
}