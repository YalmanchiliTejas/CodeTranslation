#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define nl printf("\n")
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
ll pow1(ll a, ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a;
		}
		a=a*a;
		b=b>>1;
	}
	return ans;
}
ll dp[3005][3005][2];
ll arr[3005];
ll vis[3005][3005][2];
ll solve(ll i,ll j,int turn)
{
	if(i == j)
	{
		if(!turn)
			return arr[i];
		return -arr[i];
	}
	if(vis[i][j][turn])
		return dp[i][j][turn];
	if(!turn)
		dp[i][j][turn] = max(arr[j]+solve(i,j-1,1),arr[i]+solve(i+1,j,1));
	else
		dp[i][j][turn] = min(-arr[j]+solve(i,j-1,0),-arr[i]+solve(i+1,j,0));
	vis[i][j][turn] = 1;
	return dp[i][j][turn];
}
int main()
{
	ll n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<(solve(0,n-1,0))<<endl;
	return 0;
}