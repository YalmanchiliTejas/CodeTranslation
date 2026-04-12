#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define forA(i,a,n,x) for(auto i=a;i<n;i+=x)
#define forD(i,a,n,x) for(auto i=n-1;i>=0;i-=x)
#define ranit(it,n) for(auto it:n)
#define testCases ll t;cin>>t;while(t--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define init(a,x) memset(a,x,sizeof(a))

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	ll n; cin>>n; vll v(n); forA(i,0,n,1)cin>>v[i];
	vll prefix(n); prefix[0]=v[0]; forA(i,1,n,1)prefix[i]=prefix[i-1]+v[i];
	ll ans=0;
	forA(i,0,n-1,1)
	{
		ll x = prefix[n-1]-prefix[i];
		ll temp = ((x%mod)*(v[i]%mod))%mod;
		ans = (ans+temp)%mod;
	}
	cout<<ans;
	return 0;
}