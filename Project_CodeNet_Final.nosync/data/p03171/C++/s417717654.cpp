#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll dp[3001][3001];
int main()
{
	int n;
	cin>>n;
	vector<ll>a(n);
	for(ll&x :a)cin>>x;
	int c = n%2?1:-1;
	for(int i=0;i<n;i++)dp[i][i] = a[i]*c;
	c*=-1;
	for(int j=1;j<n;j++)
	{
		for(int i=0;i+j<n;i++){
			if(c == 1)dp[i][i+j] = max(dp[i+1][i+j]+a[i],dp[i][i+j-1]+a[i+j]);
			else dp[i][i+j] = min(dp[i+1][i+j]-a[i],dp[i][i+j-1]-a[i+j]);
		}
		c*=-1;
	}
	cout<<dp[0][n-1];
}
