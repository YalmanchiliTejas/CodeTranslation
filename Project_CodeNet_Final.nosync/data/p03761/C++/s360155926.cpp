#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a(26,50);
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		vector<int> b(26);
		for(int j=0;j<s.size();j++)
		b[s[j]-'a']++;
		for(int j=0;j<26;j++)
		a[j]=min(a[j],b[j]);
	}
	string ans;
	for(int i=0;i<26;i++)
	{
	for(int j=0;j<a[i];j++)
	{
		ans+=('a'+i);
	}}
	cout<<ans<<endl;
	return 0;
}