#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/
 
#define pll              pair <long long,long long>
#define pb               push_back
#define ll               long long
#define ff               first
#define ss               second
#define D(x)             cerr<<#x " = "<<(x)<<endl
#define vll              vector <ll>
#define IOS              ios_base::sync_with_stdio(0); cin.tie(NULL);
#define endl             '\n'   
using namespace std;
const ll MOD = 998244353;
const ll N = 3e3+1;
const ll S = 3e3+1;
ll dp[N][S];
ll a[N];
ll n,s;
//modulo arithmetic
inline ll add(ll a, ll b)
{
	ll res = a + b;
	if(res >= MOD)
		return res - MOD;
	return res;
}

inline ll mult(ll a, ll b)
{
	ll  res = a;
	res *= b;
	if(res >= MOD)
		return res % MOD;
	return res;
}

inline ll sub(ll a, ll b)
{
	return (a%MOD-b%MOD+MOD)%MOD;
}
int main()
{
    IOS
 	// freopen("input.txt","r",stdin);
 	// freopen("output.txt","w",stdout);
 	// freopen("error.txt","w",stderr);
 	memset(dp,0,sizeof(dp));
 	cin>>n>>s;
 	for(ll i=1;i<=n;i++)
 	{
 		cin>>a[i];
 	}	
 	//dp[0][0]=1;
 	ll ans=0;
 	for(ll i=1;i<=n;i++)
 	{
 		dp[i][a[i]]=add(dp[i][a[i]],i);
 		for(ll j=0;j<N;j++)
 		{	
 			dp[i][j]=add(dp[i][j],dp[i-1][j]);
 			if(j+a[i]<N)
 			{
 				dp[i][j+a[i]]=add(dp[i][j+a[i]],dp[i-1][j]);
 			}
 		}
 		// 	cout<<endl;
 		// for(ll j=0;j<=s;j++)
 		// {
 		// 	cout<<j<<" "<<dp[i][j]<<endl;
 		// }
 		ans=add(ans,mult(sub(dp[i][s],dp[i-1][s]) , (n-i+1)));
 		//cout<<(dp[i][s]) * (n-i+1)<<endl;
 	}
 	cout<<ans<<endl;
    return 0;
}