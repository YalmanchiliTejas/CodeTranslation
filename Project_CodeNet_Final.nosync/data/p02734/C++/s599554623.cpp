#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int dp[3005][3005],t[3005][3005];
int a[3005],mod=998244353;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],dp[i][a[i]]=i;
	FOR(i,2,n){
		FOR(j,a[i],m)t[i][j]=(dp[i-1][j-a[i]]+dp[i][j])%mod;
		FOR(j,0,m)dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		FOR(j,a[i],m)dp[i][j]=(dp[i-1][j-a[i]]+dp[i][j])%mod;
	}
	int ans=0;
	FOR(i,1,n){
		ans=(ans+t[i][m]*(n-i+1))%mod;
	}
	cout<<ans;
	RE 0;
}


