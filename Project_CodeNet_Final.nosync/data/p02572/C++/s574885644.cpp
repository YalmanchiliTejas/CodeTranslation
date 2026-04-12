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
const ll MOD = 1e9+7;
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
	ll n;
	cin>>n;
	ll a[n];
	for(ll &x:a)
		cin>>x;
	ll sum=0;
	ll ans=0;
	for(ll x:a)
	{
		ans=add(ans,mult(sum,x));
		sum=add(sum,x);
	}		
	cout<<ans<<endl;
    return 0;
}