#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cache[105][2][5];
string s;
ll k;
ll dp(ll n,ll f,ll cnt)
{
	if(cnt>k)
		return 0;
	if(n==s.size())
	{
		if(cnt==k)
		{
			return 1;
		}
		return 0;
	}

	if(cache[n][f][cnt]!=-1)
		return cache[n][f][cnt];
	ll m;
	if(f==1)
		m=9;
	else
		m=s[n]-'0';
	ll ans=0;
	for(ll i=0;i<=m;i++)
	{
		if(i!=0)
		{
			if(i!=m)
				ans+=dp(n+1,1,cnt+1);
			else
				ans+=dp(n+1,f,cnt+1);

		}
		else
		{
			if(i!=m)
				ans+=dp(n+1,1,cnt);
			else
				ans+=dp(n+1,f,cnt);
		}


	}
	return cache[n][f][cnt]=ans;
}

int main()
{
	cin>>s;
	cin>>k;
	memset(cache,-1,sizeof(cache));
	cout<<dp(0,0,0);
}