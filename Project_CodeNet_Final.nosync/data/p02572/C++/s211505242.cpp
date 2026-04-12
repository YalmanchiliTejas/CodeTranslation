#include <bits/stdc++.h>
#define ll long long int
#define N 1000
#define M 1000000007
#define f(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define bs binary_search
#define debug(x) cout << #x << " = " << x << endl
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define all(x) x.begin(), x.end()
#define PI 3.14159265
#define cot cout.tie(0)
using namespace std;
/**
  * @author :: Rishabh
  *
  */
int main()
{
	ibs;
	cti;
	ll n;
	cin>>n;
	ll a[n];
	ll dp[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dp[0]=a[0];
	dp[1]=a[1]*a[0];
	ll b[n];
	b[0]=a[0];
	b[1]=a[0]+a[1];
	for(ll i=2;i<n;i++)
	{
		b[i]=b[i-1]+a[i];
		b[i]=b[i]%M;
	}
	for(ll i=2;i<n;i++)
	{
		dp[i]=dp[i-1]+(a[i]*b[i-1]);
		dp[i]=dp[i]%M;
	}
	cout<<dp[n-1]%M<<"\n";
	return 0;
}