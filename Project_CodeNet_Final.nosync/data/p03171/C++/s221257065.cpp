#include <bits/stdc++.h>
#ifdef LOCAL
#include <pprint.hpp>
#endif
#define endl "\n";
#define pb push_back
#define md 1000000007
#define ll long long int
#define all(v) v.begin(),v.end()
ll power(ll a,ll b){ll z=1;while(b){if(b&1){z*=a;z%=md;}a*=a;a%=md;b/=2;}return z%md;}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N=3001;
ll n,sum=0;
ll dp[N][N];
vector<ll> val;

ll solve(ll i,ll j,ll t){
	if(i>j)
		return 0;
	ll &ans=dp[i][j];
	if(ans!=-1)
		return ans;
	ans=0;
	if(t==0){
		ans = max(val[i] +solve(i+1,j,!t),val[j]+solve(i,j-1,!t));
	}
	else{
		ans = min(solve(i+1,j,!t),solve(i,j-1,!t));		
	}
	return ans;
}

int main(){
	//You need to change array size!
	#ifndef LOCAL
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	#endif 
	memset(dp,-1,sizeof dp);
	cin>>n;
	val.resize(n+1);
	for(int i=1;i<=n;++i){
		cin>>val[i];	
		sum+=val[i];
	}
	
	ll x=solve(1,n,0);
	
	cout<<2*x - sum<<endl;	


	return 0;	
}