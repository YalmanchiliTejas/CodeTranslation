#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;	

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define test() ll t;cin>>t;for(ll test = 1;test<=t;test++)
#define f first
#define s second
#define pb push_back
#define nl cout<<"\n"
#define MOD(x) ((x%P)+P)%P
#define vec(v) loop(i,0,v.size()) cout<<v[i]<<" "; nl
const int N = 100005;
const ll P = 1000000007;
const double eps = 1e-6;

ll dp[3005][3005];
int main()
{
	fastio();

	int n; cin>>n;

	ll arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];


	for(int i=0; i<n; i++)
		dp[i][i] = arr[i];	

	for(int len=2; len<=n; len++)
	{
		for(int i=0; i<n-len+1; i++)
		{
			int j = i+len-1;
			dp[i][j] = max(arr[j]-dp[i][j-1], arr[i]-dp[i+1][j]);
		}
	}

	cout<<dp[0][n-1],nl;

	//cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}