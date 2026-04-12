/*
 * drish1001
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>  
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std;
#define     pb                 push_back
#define     mp                 make_pair
#define     ff                 first
#define     ss                 second
#define    MOD                1000000007
#define     pll                pair<ll,ll>
void        sorta(auto &v)     {sort(v.begin(),v.end());} 
void        sortd(auto &v)     {sort(v.begin(),v.end(), greater<>());} 
void        fast()            {ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
typedef        long long        ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> magic; 

//all variables and functions be1ow this ..


int main()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
		cin >> v[i];
	vector<ll> sum(n);
	sum[n-1] = v[n-1];
	for(ll i=n-2;i>=0;i--)
	{
		sum[i] = (v[i]+sum[i+1])%MOD;
	}
	ll ans=0;
	for(ll i=0;i<n-1;i++)
	{
		ll temp = (v[i]*sum[i+1])%MOD;
		ans=(ans+temp)%MOD;
	}
	cout << ans << endl;
}
