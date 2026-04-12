/******************************************
* AUTHOR : kamesh_11 *
* INSTITUTION : GVPCOE *
******************************************/

#include <bits/stdc++.h>
using namespace std;

#define pi 3.141592653589793
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bs binary_search
#define endl '\n'
#define start_clock clock_t beginn=clock()
#define end_clock clock_t endd=clock()
#define cal_exec_time double time_spent=(double)(endd-beginn)/CLOCKS_PER_SEC
#define print_exec_time cout<<endl<<time_spent<<" secs"

typedef long long int ll;

const ll MOD = 1000000007;

ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

ll calculate(ll arr[], ll n, ll i, ll j, ll taro, vector<vector<vector<ll>>>& dp){
	if(i>j || i>=n || j<0)
		return 0;

	if(dp[i][j][taro] != -1)
		return dp[i][j][taro];

	if(taro){
		ll l = arr[i] + calculate(arr, n, i+1, j, !taro, dp);
		ll r = arr[j] + calculate(arr, n, i, j-1, !taro, dp);
		return dp[i][j][taro] = max(l, r);
	}
	if(!taro){
		ll l = -arr[i] + calculate(arr, n, i+1, j, !taro, dp);
		ll r = -arr[j] + calculate(arr, n, i, j-1, !taro, dp);
		return dp[i][j][taro] = min(l, r);
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];

	vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
	cout<<calculate(arr, n, 0, n-1, 1, dp);

	return 0;
}