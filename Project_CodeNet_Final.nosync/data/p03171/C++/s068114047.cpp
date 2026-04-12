#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	#define PI 3.14159265358979
	#define EPS 1e-8
	#define mod  1000000007
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
 
	const ll INF=1e18;	
	const int N=5e5+50;
 
	
	vector<ll> pref,v;
	ll dp[3005][3005];
	
	ll solve(ll l,ll r)
	{
		if(l>r)
			return 0;
		if(dp[l][r]!=-1)
			return dp[l][r];
		ll s=pref[r];
		if(l>0)
			s-=pref[l-1];
		ll ans=max(s-solve(l+1,r),s-solve(l,r-1));
		return dp[l][r]=ans;
	}
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(0);
		
		int n;
		cin>>n;
		v=vector<ll> (n);
		pref=vector<ll> (n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			pref[i]=v[i];
			if(i)
			{
				pref[i]+=pref[i-1];
			}
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
				dp[i][j]=-1;
		}
		ll y=solve(0,n-1);
		ll x=pref[n-1]-y;
		cout<<y-x;
	}
