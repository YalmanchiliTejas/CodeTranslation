#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define pb push_back
#define f first
#define s second
#define pi 3.141592653589793238
using namespace std;

ll gcd( ll a, ll b )
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd( b, a%b );
	}
}
ll lcm (ll a, ll b)
{
	return (a*b)/gcd(a,b);
}

ll power(ll a, ll b)	//a is base, b is exponent
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	if(b%2 == 1)
		return (power(a,b-1)*a)%mod;
	ll q = power(a,b/2);
	return (q*q)%mod;
}
ll n;
ll arr[4000];
ll dp[3005][3005];

ll solve(ll l,ll r)
{
	if(r<l) return 0;
	else if(dp[l][r]!=-1) return dp[l][r];
	return dp[l][r]= max (min (solve (l+2, r), solve (l+1, r-1)) + arr[l],
					min (solve (l+1, r-1), solve (l, r-2)) + arr[r]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >>n;
	ll sum=0;
	for(int i =0;i<n;i++) cin >> arr[i],sum+=arr[i];
	for(int i =0;i<3005;i++) for(int j =0;j<3005;j++) dp[i][j]=-1;
	for(int i =0;i<n;i++) dp[i][i] = arr[i];
	ll a = solve(0,n-1);
	ll b = sum - a;

	cout << a-b << endl;
	


	return 0;
}


//Hello, this is a snippet.
