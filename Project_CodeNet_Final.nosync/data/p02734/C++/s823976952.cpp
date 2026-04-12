#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define mod (ll)(998244353)
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
ll gcd(ll a,ll b){if(!b)return a;else return gcd(b,a%b);}
ll dp[3333][3333][2];
int main()
{
	ll n,s;
	cin>>n>>s;
	vector<ll>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<=s;j++){
		  dp[i+1][j][0]+=dp[i][j][0];
		  if(!j)dp[i+1][j][0]++;
		  dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1];
		  if(!j)dp[i+1][j][1]++;
		  dp[i+1][j][0]%=mod;
		  dp[i+1][j][1]%=mod;
		  if(j+a[i]<=s){
			  dp[i+1][j+a[i]][0]+=dp[i][j][0];
			  dp[i+1][j+a[i]][1]+=dp[i][j][0];
			  if(!j){
				  dp[i+1][j+a[i]][0]++;
				  dp[i+1][j+a[i]][1]++;
			  }
		  }
		  dp[i+1][j][0]%=mod;
		  dp[i+1][j][1]%=mod;
		}
	}
	cout<<dp[n][s][1]%mod;
}

