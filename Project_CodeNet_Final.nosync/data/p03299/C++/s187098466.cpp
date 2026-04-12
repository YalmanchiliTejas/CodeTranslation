#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int inf=1e9+9;
int powmod(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
pair<int,int> Solve(vector<int> a)
{
	int mn=inf;
	for(int i:a) mn=min(mn,i);
	int cnt=0;
	for(int i:a) cnt+=i==mn;
	int all=powmod(2,cnt);
	int only=2;
	vector<int> tmp;
	for(int i:a)
	{
		if(i==mn && tmp.size())
		{
			pair<int,int> ans=Solve(tmp);
			tmp.clear();
			all=(ll)all*((ans.first+ans.second)%mod)%mod;
			only=(ll)only*ans.second%mod;
		}
		if(i!=mn) tmp.push_back(i-mn);
	}
	if(tmp.size())
	{
		pair<int,int> ans=Solve(tmp);
		tmp.clear();
		all=(ll)all*((ans.first+ans.second)%mod)%mod;
		only=(ll)only*ans.second%mod;
	}
	all-=only;
	if(all<0) all+=mod;
	only=(ll)only*powmod(2,mn-1)%mod;
	all+=only;
	if(all>=mod) all-=mod;
	return make_pair(all,only);
}
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<int> a(n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	printf("%i\n",Solve(a).first);
	return 0;
}