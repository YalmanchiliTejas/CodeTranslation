#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]
typedef vector< int > vi;
typedef vector< ll > lvi;
typedef vector< vi > vvi;
typedef vector< lvi > lvvi;
typedef pair< int,int > ii;
typedef pair< ll,ll > lii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)//remember i is an iterator
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
ll nck[1005][1005],dp[1005][1005],dp2[1005][1005];
ll n,a,b,c,d;
ll modpow(ll x,ll y)
{
	ll ans=1;
	while(y>0)
	{
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y=y>>1;
	}
	return ans;
}
ll recurs(ll i,ll j)
{
	if(i<0) return 0;
	if(j>b) return 0;
	if(i==0) return 1;
	if(j==b) /*return 1;*/
	{
		if((i%b)!=0) return 0;
		else
		{
			ll k=i/j;
			if(k>=c && k<=d)
			{
				return dp2[j][k];
			}
			else return 0;
		}
	}
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]=recurs(i,j+1);
	// if(i==3 && j==1) cout<<dp[i][j]<<"***\n";
	for(int k=c;k<=d;k++)
	{
		if(k*j >i) break;
		dp[i][j]=(dp[i][j]+(((recurs(i-k*j,j+1)*nck[i][k*j])%mod)*dp2[j][k])%mod)%mod;
	}
	// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	return dp[i][j];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	cin>>n>>a>>b>>c>>d;
	nck[1][1]=1;
	nck[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		nck[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			nck[i][j]=(nck[i-1][j]+nck[i-1][j-1])%mod;
		}
	}
	for(int i=a;i<=b;i++)
	{
		dp2[i][1]=1;
		for(int j=2;j<=d;j++)
		{
			if(i*j >n) break;
			dp2[i][j]=(dp2[i][j-1]*nck[i*j][i])%mod;
			dp2[i][j]=(dp2[i][j]*modpow(j,mod-2))%mod;
		}
	}
	memset(dp,-1,sizeof(dp));
	ll ans=recurs(n,a);
	cout<<ans<<endl;
	return 0;
}