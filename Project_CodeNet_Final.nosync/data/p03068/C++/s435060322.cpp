#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
using namespace std;
int n,k;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s>>k;
	for (int i=0;i<s.size();++i)
	{
		if (s[i]!=s[k-1]) cout<<"*";
		else cout<<s[i];
	}
	return 0;
}