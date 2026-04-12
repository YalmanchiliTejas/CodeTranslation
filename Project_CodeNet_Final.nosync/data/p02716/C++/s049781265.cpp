#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
#define fi first
#define se second
#define mod 1000000007
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
ll dp[200005][3];
ll a[200005];
ll n;
ll func(ll pos,ll k,ll num)
{
	if(pos>n||num==n/2)
		return 0;
	if(dp[pos][k]!=-1)
		return dp[pos][k];
	ll d=LLONG_MIN,j;
	for(j=0;j<=k;j++)
		d=max(d,func(pos+2+j,k-j,num+1)+a[pos]);
	for(j=1;j<=k;j++)
		d=max(d,func(pos+j,k-j,num));
	dp[pos][k]=d;
	return d;
}
int main()
{
	ios;
	memset(dp,-1,sizeof(dp));
	ll i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(n==1)
	{
		cout<<0<<endl;
		exit(0);
	}
	if(n%2)
		cout<<func(1,2,0)<<endl;
	else
		cout<<func(1,1,0)<<endl;
}
