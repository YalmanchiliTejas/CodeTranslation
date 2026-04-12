#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define sc second
#define N 3005
#define endl "\n"
#define mod 1000000007
ll n,ar[N]; ll dp[N][N];
ll maxval(ll l,ll r,ll chance){
	if(l==r){
		if(chance%2==0) return ar[l];
		else return -ar[l];
	}
	if(dp[l][r]!=-1){
		return dp[l][r];
	}

	if(chance%2==0){
		return dp[l][r]=max(maxval(l+1,r,chance+1)+ar[l],maxval(l,r-1,chance+1)+ar[r]);
	}	
	else {
		return dp[l][r]=min(maxval(l+1,r,chance+1)-ar[l],maxval(l,r-1,chance+1)-ar[r]);
	}
}
int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll i,j,k,l;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}

	k=maxval(1,n,2);
	cout<<k;
	return 0;
}
