#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define precise(x) cout<<fixed<<setprecision(12)<<x
#define test cout<<"#";

const ll INF = 1e18L + 5;

ll ans[3001][3001][2];
ll solve(vector<ll> &v, ll s, ll e, ll turn)
{
	if(s>e)
		return 0;
	if(ans[s][e][turn]!=-1)
		return ans[s][e][turn];
	if(turn == 0)
		return ans[s][e][turn] = min(solve(v, s+1, e, 1), solve(v, s, e-1, 1));
	else
		return ans[s][e][turn] = max(solve(v, s+1, e, 0)+v[s-1], solve(v, s, e-1, 0)+v[e-1]);	
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
	ll x = solve(v, 1, n, 1);
	ll y = sum-x;
	cout<<x-y;
}