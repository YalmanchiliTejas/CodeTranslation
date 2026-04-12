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
ll dp[10005][2][105]; 
ll d;
string k;
ll builddp(ll pos,int flag,int rem){
	// cout<<pos<<" "<<flag<<" "<<rem<<" "<<res<<endl;
	if(pos==k.size()){
		return (rem==0);
	}
	ll &ans=dp[pos][flag][rem];
	if(ans!=-1) return ans;
	ans=0;
	int num=k[pos]-'0';
	if(flag==0){
		for(int i=0;i<=num;i++){
			// string res1=res;
			// res1+=(i+'0');
			ans=(ans+builddp(pos+1,(i<num),(rem+i)%d))%MOD;
			ans%=MOD;
		}
	}
	else{
		for(int i=0;i<=9;i++){
			// string res1=res;
			// res1+=(i+'0');
			ans=(ans+builddp(pos+1,1,(rem+i)%d))%MOD;
			ans%=MOD;
		}
	}
	// cout<<"After DP-====>>"<<pos<<" "<<flag<<" "<<rem<<" "<<ans<<endl;
	return ans;
}
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		// string k;
		// ll d;
		cin>>k>>d;
		// string res="/";
		minus(dp);
		builddp(0,0,0);
		// builddp(0,k,1,0,0,d,res);
		// cout<<"ans="<<dp[0][0][0]<<endl;
		ll ans=(dp[0][0][0]-1+MOD)%MOD;
		cout<<ans<<endl;
	}
}