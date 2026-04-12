/*"You can do anything you set your mind to,man" - Eminem*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define llpow(a,b) (ll)(pow(a,b)+0.5)
#define l_b(a,val) min((int)a.size()-1, (int)(lower_bound(a.begin(),a.end(),val)-a.begin()))
#define f first
#define up(a,b) max(a,b)
#define s second
#define INF 9223372036854775807
const  int mod = 1000000007;
template <typename T> T add(T& a, T b){a+=b;while(a>=mod)a-=mod;while(a<0)a+=mod;}
template <typename T> T mul(T& a, T b){a*=b;while(a>=mod)a-=mod;while(a<0)a+=mod;}
template <typename T> T up_self(T& a, T b){a = up(a,b);}
template <typename T> T min_self(T& a, T b){a = min(a,b);}
ll binexpomodulo(ll x, ll y){ll res =1;x%=mod;if(!x)return 0;while(y){if(y&1){mul(res, x);}mul(x,x);y>>=1;}return res;}
ll nCrInOr(ll n, ll r){ll res = 1;if(r>n-r)r = n-r;ll rin = 1;for(ll i = 1; i <=r ; i++)rin = (rin*i)%mod;rin = binexpomodulo(rin,mod-2);for(ll i = 1; i <= r; i++)res = (res*(n-i+1))%mod;res = (res*rin)%mod;return res;}
int msb(ll n){int ans;for(int i = 0 ; i < 64;  i++)if(n&(1LL<<i))ans = i+1;return ans;}
int main()
{
	int n; cin>>n;
	vector<vector<ll>> dp(n,vector<ll> (n));
	ll a[n];
	for(int i = 0 ; i < n; i++)
		cin>>a[i];	
	for(int l = n-1; l>=0; l--){
		for(int r = l; r<n; r++){
			if(l==r)
				dp[l][r] = a[l];
			else
				dp[l][r] = up(a[r]-dp[l][r-1],a[l]-dp[l+1][r]); 
		}
	}
	cout<<dp[0][n-1]<<endl;
  	return 0;
}