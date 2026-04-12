#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
 
#define mo 1000000007
#define inf 1e18
#define rep(i, s, n) for (ll i = s; i < n; i = i + 1)
#define rrep(i,s,n) for(ll i=s;i>=n;i--)
#define adiii \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);  \
  cout.tie(NULL);									
 
ll mod(ll n) { return (n % (ll)mo + (ll)mo)%(ll)mo;}
ll gcd(ll a,ll b) {if (b == 0) return a;return gcd(b, a % b);}
 
ll binpow(ll a, ll b) {ll res = 1;while (b > 0) {if (b & 1) res = res * a;a = a * a;b >>= 1;}return res;}

int main(){
	ll n;cin>>n;
	vector <ll> a(n);
	rep(i,0,n) cin>>a[i];
	vector<vector<ll>> dp(n,vector<ll>(n));
	
	rrep(l,n-1,0){
		rep(r,l,n){
			if(l==r) dp[l][r] = a[l];
			else{
				dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
			}
		}
	}
	cout<<dp[0][n-1];
}
