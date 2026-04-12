
// Problem : C - Sum of product of pairs
// Contest : AtCoder - AtCoder Beginner Contest 177
// URL : https://atcoder.jp/contests/abc177/tasks/abc177_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int main()
{
	fast;
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		ll n,res=0;
		cin >> n;
		ll a[n];
		for(ll i=0;i<n;i++)
			cin>>a[i];
		ll pre[n-1];
		pre[0] = a[0];
		for(ll i=1;i<n-1;i++)
		{
			pre[i] = pre[i-1] + a[i];
		}
		for(ll i=0;i<n-1;i++)
		{
			res = (res%mod + (pre[i]%mod * a[i+1]%mod)%mod)%mod;
		}
		cout<<res<<"\n";
	}
	return 0;
}