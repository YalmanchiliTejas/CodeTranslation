#include<bits/stdc++.h>
using namespace std;
# define pb push_back
# define FOR(i,a,n) for(int i=a;i<n;i++)
# define mp make_pair
# define RFOR(i,a,n) for(int i=n;i>a;i--)
# define pii pair<long long int,long long int>
#define ub upper_bound
#define lb lower_bound
#define MOD 1000000007
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> vec;
	ll a;
	ll dp[3001][3001];
	for(int i=0;i<n;i++)
	{
		cin>>a;
		vec.pb(a);
	}
	
	for(int l=n-1;l>=0;l--)
	{
		for(int r=l;r<n ;r++)
		{
			if(l==r)
			dp[l][r]=vec[l];
			else
			dp[l][r]=max(vec[l]-dp[l+1][r],vec[r]-dp[l][r-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
}