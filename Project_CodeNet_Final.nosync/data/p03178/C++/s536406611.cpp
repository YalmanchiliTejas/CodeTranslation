#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define takeline cin.ignore();
#define sc second
#define N 10005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
char ar[N]; ll d,n; ll dp[10001][2][101];
ll maxval(ll i,ll flg,ll rem){
	if(i==n){
		if(rem==0) return 1;
		else return 0;
	}
	if(dp[i][flg][rem]!=-1){
		return dp[i][flg][rem];
	}
	if(flg){
		ll c=0;
		for(ll j=0;j<=9;j++){
			c=(c%mod+maxval(i+1,1,(rem+j)%d)%mod)%mod;
		}
		return dp[i][flg][rem]=c%mod;
	}
	else{
		ll c=0,j;
		for(j=0;j<(ar[i]-'0');j++){
			c=(c%mod+maxval(i+1,1,(rem+j)%d)%mod)%mod;
		}
		c=(c%mod+maxval(i+1,0,(rem+j)%d)%mod)%mod;
		return dp[i][flg][rem]=c%mod;
	}
}
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>ar;
	ll i,j,l,k; n=strlen(ar);
	cin>>d;
	
	ll an=maxval(0,0,0)%mod;
	an=(an-1+mod)%mod;
	cout<<an;
	return 0;
}