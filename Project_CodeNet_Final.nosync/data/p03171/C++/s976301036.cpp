/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ld long double
#define zero(a) memset((a),0,sizeof((a)))
#define one(a) memset((a),1,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)))
#define all(g) g.begin(),g.end()
#define ppb pop_back
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); } 
ll dp[3001][3001][2];
ll find(vector<ll>&v,ll l,ll r,ll chance){
	if(l>r) return 0;
	ll &ans=dp[l][r][chance];
	if(ans!=-1) return ans;
	if(chance==0){
		ans=max(v[l]+find(v,l+1,r,1-chance),v[r]+find(v,l,r-1,1-chance));
	}
	else{
		ans=min(-v[l]+find(v,l+1,r,1-chance),-v[r]+find(v,l,r-1,1-chance));
	}
	return ans;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j][0]=-1;
				dp[i][j][1]=-1;
			}
		}
		cout<<find(v,0,n-1,0)<<endl;
	}
}