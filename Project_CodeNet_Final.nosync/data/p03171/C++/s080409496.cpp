#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N=1e6+5,inf=1e18,mod=1e9+7;
#define test ll testcases;cin>>testcases; while(testcases--)
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define sz(x) ((ll)((x).size()))
const ld pi=3.141592653589793238;

bool check_prime(ll n)
{
	ll flag=0,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(n==1)
	{
		return false;
	}
	else if(flag==0 || n==2 || n==3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ll fastexpo(ll a,ll b,ll MOD) 
{
	ll result=1;
	while(b>0)
	{
		if(b%2==1)
		{
			result=(result*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;
	}
	return result;
}
ll a[3005];
ll cum[3005];
ll n;
ll dp[3005][3005];

ll sum(ll l,ll r)
{
	return cum[r]-cum[l-1];
}

ll solve(ll l,ll r)
{
	if(dp[l][r]!=-1)
	{
			return dp[l][r];
	}
	if(l>r)
	{
		return 0;
	}
	dp[l][r]=max(a[l]+sum(l+1,r)-solve(l+1,r),a[r]+sum(l,r-1)-solve(l,r-1));
	return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,ans;
	cin>>n;
	cin>>a[0];
	cum[0]=a[0];
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		cum[i]=cum[i-1]+a[i];
	}    
	memset(dp,-1,sizeof(dp));
	ans=solve(0,n-1);
	ans=2*ans-cum[n-1];
	cout<<ans<<"\n";
	return 0;
}