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
#define sc second
#define takeline cin.ignore();
#define iactive cout.flush();
#define N 3005
#define endl "\n"
#define mod 1000000007
#define PI 3.141592653589793
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n,k; ll ar[N],dp[N][N][2];
ll findans(ll l,ll r,ll flg){
	if(l>r) return 0;

	if(dp[l][r][flg]!=-1){
		return dp[l][r][flg];
	}

	if(flg){
		ll a,b;
		a=findans(l+1,r,1-flg)+ar[l];
		b=findans(l,r-1,1-flg)+ar[r];
		return dp[l][r][flg]=max(a,b);
	}
	else{
		ll a,b;
		a=findans(l+1,r,1-flg)-ar[l];
		b=findans(l,r-1,1-flg)-ar[r];
		return dp[l][r][flg]=min(a,b);
	}
}
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,l,k;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}
	memset(dp,-1,sizeof(dp));
	ll an=findans(1,n,1);
	cout<<an;
	return 0;
}