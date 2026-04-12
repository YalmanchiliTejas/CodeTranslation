#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>

vector <ll> v;
ll mem[3005][3005][2];

ll fep(ll x, ll y, ll mod)
{ll res=1;while(y>0){if(y&1)res=(res*x)%mod;
    y=y>>1;x=(x*x)%mod;}return res%mod;}
    
ll dp(ll i, ll j, ll k)
{
	if(mem[i][j][k]!=-1)
		return mem[i][j][k];
	if(i==j)
		mem[i][j][k]=v[i];
	else
		mem[i][j][k]=max(v[i]-dp(i+1,j,k^1),v[j]-dp(i,j-1,1-k));
	return mem[i][j][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	ll n,i,m,j,k,x,y,a,b;
	string s;
	
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> x;
		v.pb(x);
	}
	memset(mem,-1,sizeof(mem));
	cout << dp(0,n-1,0);
	return 0;
}
