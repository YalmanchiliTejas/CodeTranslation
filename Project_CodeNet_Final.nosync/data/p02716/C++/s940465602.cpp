
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define all(v)  v.begin(),v.end()
#define pb push_back
#define size(v)  (int) v.size()
#define fast ios_base:: sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
ll power_mod(ll a,ll x){if(x==0) return 1;ll y=power_mod(a,x/2);ll ans=(y*y)%mod; if(x%2) ans=(ans*a)%mod;return ans;}
ll inv(ll a){return power_mod(a,mod-2);}    
ll power(ll a, ll x){ if(x==0) return 1; ll y= power(a,x/2); ll ans=(y*y); if(x%2) ans*=a; return ans;}


int main(){
	fast;
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1; i<=n;i++) cin>>a[i];
    ll dp[n+1][2]={};
    dp[1][0] = 0;
    dp[1][1] = a[1];
	for(ll i = 2; i <= n ; i++){
		 if(i%2 == 0){
		 	  dp[i][0] = max(dp[i-1][1],dp[i-2][0]+a[i]);
		 }
		 else{
		 	 dp[i][0] = max(dp[i-1][0],dp[i-2][0]+a[i]);
		 	 dp[i][1] = dp[i-2][1]+a[i];
		 }
       
	}

	cout<<dp[n][0]<<endl;
 
}
