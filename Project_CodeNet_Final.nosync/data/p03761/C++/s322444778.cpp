#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[50][26];
ll ans[26];

int main()
{
	for(int i = 0 ;i<26;i++)
	ans[i]=1e9;
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i =0;i<n;i++)
	{
		cin >> s[i];
		for(int j = 0 ;j<s[i].size();j++)
		{
			cnt[i][s[i][j]-'a']++;
		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<26;j++)
		{
			ans[j] = min(ans[j],cnt[i][j]);
		}
	}
	for(int i = 0;i<26;i++)
	{
		for(int j = 0 ;j<ans[i];j++)
		{
			cout<<(char)('a'+i);
		}
	}
	cout<<endl;


	return 0;
}