#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<ll,ll>;
//const int 1001001001;
const int NMAX=8;
const ll MOD=1000000007;
const ll INF=1e18;
const int mod = 998244353;
ll dp[200005][4];

int main(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n)cin>>a[i];
	ll k=n%2+1;//何個余分な数が入るか

	rep(i,n+1)rep(j,k+1)dp[i][j]=-INF;
	dp[0][0]=0;
	rep(i,n)rep(j,k+1){
		dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
		//選ばれない時
		if((i+j)%2==0){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i]);
		}
		else{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
	//	cout<<dp[i+1][j]<<'i'<<i<<'j'<<j<<endl;


	}
	ll ans=dp[n][k];
	cout<<ans;
}
