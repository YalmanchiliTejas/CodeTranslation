#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M=1002;
const ll mod=1e9+7;
ll dp[M][M],cmb[M][M],fact[M][M];
ll power(ll a,ll b)
{
	ll val=1;
	while(b)
	{
		if(b%2)
			val=(val*a)%mod;
		b/=2;
		a=(a*a)%mod;
	}
	return val;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	dp[a-1][0]=1;
	cmb[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		cmb[i][0]=1;
		for(int j=1;j<=i;j++)
			cmb[i][j]=(cmb[i-1][j]+cmb[i-1][j-1])%mod;
	}
	// cout<<cmb[4][2]<<endl;
	fact[0][1]=1;
	for(ll i=1;i<=n;i++)
	{
		fact[i][1]=(fact[i-1][1]*i)%mod;
		for(ll j=2;j<=n;j++)
			fact[i][j]=(fact[i][j-1]*fact[i][1])%mod;
	}	
	for(int i=a;i<=b;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(int k=c;k<=d;k++)
			{
				if(i*k>j)
					break;
				ll res = (cmb[j][i*k]*dp[i-1][j-i*k])%mod;
				res = (res*fact[k*i][1])%mod;
				res = (res*power(fact[i][k],mod-2))%mod;
				res = (res*power(fact[k][1],mod-2))%mod;
				dp[i][j]=(dp[i][j]+res)%mod;
			}
		}
	}
	cout<<dp[b][n]<<"\n";
	
	return 0;
}