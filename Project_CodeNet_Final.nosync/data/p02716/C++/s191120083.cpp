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
#define N 3000005
#define endl "\n"
#define mod 1000000007
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n,ar[N]; ll dp[N][4];
ll findans(ll i,ll f1){
	if(i>n){
		if(f1<=1) return 0;
		else return -1e18;
	}
	if(dp[i][f1]!=-1){
		return dp[i][f1];
	}

	if(f1>0){
		ll a,b;
		a=findans(i+1,f1-1);
		b=findans(i+2,f1)+ar[i];
		return dp[i][f1]=max(a,b);
	}
	else return dp[i][f1]=findans(i+2,f1)+ar[i];
}
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}
	
	memset(dp,-1,sizeof(dp));
	if(n%2==0){
		ll an=max(findans(1,1),findans(2,0));
		cout<<an;
	}
	else {
		
		ll an=max(findans(1,2),findans(2,1));
		cout<<an;
	}
	return 0;
}