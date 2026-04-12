#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld double
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pll pair <ll,ll>
#define nl "\n"
string k;
ll d,n;
ll dp[10002][102][2];
ll fx(ll idx, ll su, ll fl)
{
	if(idx == n)
	{
		if(su == 0)
			return dp[idx][su][fl]=1;
		else
			return dp[idx][su][fl]=0;
	}
	if(dp[idx][su][fl] != -1)
		return dp[idx][su][fl];
	if(fl == 1)
	{
		ll sum = 0;
		for(int i=0;i<10;i++)
		{
			sum = (sum + fx(idx+1, (su+i)%d, fl))%mod;
		}
		return dp[idx][su][fl] = sum;
	}
	else
	{
		ll sum = 0;
		for(int i=0;i<k[idx]-'0';i++)
		{
			sum = (sum + fx(idx+1, (su+i)%d, 1))%mod;
		}
		sum = (sum + fx(idx+1, (su+k[idx]-'0')%d, fl))%mod;
		return dp[idx][su][fl] = sum;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>k>>d;
	ll i,j,l;
	n=k.length();
	for(i=0;i<10002;i++)
		for(j=0;j<102;j++)
			dp[i][j][0]=dp[i][j][1]=-1;
	cout<<(fx(0, 0, 0) - 1 + mod)%mod<<nl;
	return 0;
}