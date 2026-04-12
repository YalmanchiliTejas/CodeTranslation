#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int MOD = 1e9 + 7;

int dp[1001][1001];
ll fact[1001];
ll ifact[1001];
ll ipow[1001][1001];
ll modpow(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b&1) r=(r*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return r;
}

ll inv(ll a)
{
	return modpow(a,MOD-2);
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

int add(int a, int b)
{
	int res=a+b;
	while(res>=MOD) res-=MOD;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fact[0]=1;
	for(ll i = 1; i <= 1000; i++)
	{
		fact[i] = (fact[i-1]*i)%MOD;
	}
	for(ll i = 0; i <= 1000; i++)
	{
		ifact[i] = inv(fact[i]);
	}
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			ipow[i][j] = modpow(ifact[i],j);
		}
	}
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	for(int i = a; i <= b; i++)
	{
		dp[0][i] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = a; j <= b; j++)
		{
			//dp[i][j]
			if(j>a) dp[i][j] = dp[i][j-1];
			for(int k = c; k <= d && i - k*j >= 0; k++)
			{
				//use k amounts of j groups
				if(j == a)
				{
					if(i-k*j==0) dp[i][j] = add(dp[i][j], mult(ifact[k],ipow[j][k]));
				}
				else
				{
					dp[i][j] = add(dp[i][j], mult(dp[i-k*j][j-1], mult(ifact[k],ipow[j][k])));
				}
			}
			//cerr<<i<<' '<<j<<' '<<mult(dp[i][j],fact[i])<<'\n';
		}
	}
	ll ans = (dp[n][b]*1LL*fact[n])%MOD;
	cout<<ans<<'\n';
}
