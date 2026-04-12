#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define N 100005
#define mod 1000000007
//#defint mod 1e18
#define boost ios_base::sync_with_stdio(false);cin.tie(0)
#define prec(n) fixed<<setprecision(n)

#define mii unordered_map<int,int>
#define mll unordered_map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi  first

#define se second
#define pb push_back
#define mp make_pair
#define pp pop_back
#define vii vector<int>
#define vll vector<ll>
#define vpp vector<pii>
#define all(c) c.begin(),c.end()
#define tr(it,c) for(it = c.begin() ; it!=c.end() ; it++)
int inf = INT_MAX ;
ll modulo(ll num,ll MOD=mod){ return ((num%MOD)+MOD)%MOD;} // for negative integer
ll power(ll b,ll e,ll MOD=mod){ll ans=1; while(e){if(e%2) ans=(ans*b)%MOD; b=(b*b)%MOD; e/=2;} return ans;}
ll inv(ll num,ll MOD=mod){ return power(modulo(num),MOD-2,MOD); }
ll gcd(ll a,ll b){ return ((b==0) ? a:gcd(b,a%b));}
ll dp[3005][3005];

int main(){
	boost;
	int n;
	cin>>n;
	ll arr[n];
	
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	
	for(int i = n-1;i>=0;i--){
		for(int j = i;j<n;j++){
			if(i==j){
				dp[i][j] = arr[i];
			}else{
				dp[i][j] = max(arr[i] - dp[i+1][j],arr[j] - dp[i][j-1]);
			}
		}
	}
	
	cout<<dp[0][n-1];
	
	return 0;
}

//Total solved problems:- 13

