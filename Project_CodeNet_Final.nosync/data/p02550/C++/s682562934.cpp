#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M = 1e5+5;
int pos[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,x,m;
	cin>>n>>x>>m;
	vector<ll> v;
	while(1)
	{
		v.pb(x);
		pos[x] = sz(v)-1;
		x = (x*x)%m;
		if(pos[x])
			break;
	}
	ll stc = pos[x];
	ll len = sz(v)-stc;
	ll res = 0;
	for(int i=0;i<stc;i++)
	{
		res += v[i];
		n--;
		if(n==0)
			break;
	}
	ll tot = 0;
	for(int i=stc;i<sz(v);i++)
		tot += v[i];	
	res += tot*(n/len);
	for(int i=0;i<n%len;i++)
		res += v[stc+i];
	cout<<res<<"\n";
	return 0;
}