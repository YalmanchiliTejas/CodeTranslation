#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define precise(x) cout<<fixed<<setprecision(12)<<x
#define test cout<<"#";

const ll INF = 1e18L + 5;

ll ans[3001][3001];
ll solve(vector<ll> &v, ll s, ll e, ll n)
{
	if(s>e)
		return 0;
	if(ans[s][e]!=-1)
		return ans[s][e];
	ll r = n-(s+e)-1;
	if(r%2 != 0)
		return ans[s][e] = min(solve(v, s+1, e, n), solve(v, s, e-1, n));
	else
		return ans[s][e] = max(solve(v, s+1, e, n)+v[s-1], solve(v, s, e-1, n)+v[e-1]);	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> v(n);
	ll sum = 0;
	for(ll x = 0; x < n; x++)
	{
		cin>>v[x];
		sum+=v[x];
	}
	memset(ans, -1, sizeof(ans));
	ll x = solve(v, 1, n, n);
	ll y = sum-x;
	cout<<x-y;
}