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
//#define mod 1e18
#define boost ios_base::sync_with_stdio(false);cin.tie(0)
#define prec(n) fixed<<setprecision(n)

#define mii map<int,int>
#define mll map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi  first

#define se second
#define pb push_back
#define mp make_pair
#define pp pop_back
#define vii vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(c) c.begin(),c.end()
#define tr(it,c) for(it = c.begin() ; it!=c.end() ; it++)
int inf = INT_MAX ;
ll modulo(ll num,ll MOD=mod){ return ((num%MOD)+MOD)%MOD;} // for negative integer
ll power(ll b,ll e,ll MOD=mod){ll ans=1; while(e){if(e%2) ans=(ans*b)%MOD; b=(b*b)%MOD; e/=2;} return ans;}
ll inv(ll num,ll MOD=mod){ return power(modulo(num),MOD-2,MOD); }
ll gcd(ll a,ll b){ return ((b==0) ? a:gcd(b,a%b));}
ll dp[10005][105][2];
ll k,n;
string str;

ll solve(int idx,int d,int t){
	if(idx>=k){
		if(d==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	if(dp[idx][d][t]!=-1){
		return dp[idx][d][t];
	}
	
	ll ans = 0;
	if(t==1){
		for(int i = 0;i<=str[idx]-'0';i++){
			if(i==str[idx]-'0'){
				ans = (ans + solve(idx+1,(d-(i%n)+n)%n,1))%mod;
				continue;
			}
			ans = (ans + solve(idx+1,(d-(i%n)+n)%n,0))%mod;
		}
	}else{
		for(int i = 0;i<10;i++){
			ans = (ans + solve(idx+1,(d-(i%n)+n)%n,0))%mod;
		}
	}
	
	dp[idx][d][t] = ans;
	return ans;
}  

int main(){
	boost;
	cin>>str;
	cin>>n;
	k = str.size();
	
	for(int i = 0;i<10005;i++){
		for(int j = 0;j<105;j++){
			for(int m = 0;m<2;m++){
				dp[i][j][m] = -1;
			}
		}
	}
	
	
	ll ans = 0;
	ans = (ans + solve(0,0,1))%mod;
	ans = (ans - 1 + mod)%mod;
	cout<<ans;
	return 0;
}

