#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1e9+5;
const int N=2e3+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int k=n/2;
	vector<ll> a(n);
	for(ll& x:a) cin>>x;
	ll ans;
	if(n%2==0){
		vector<vector<ll>> dp(k+1,vector<ll>(2));
		for(int i=0;i<k+1;++i){
			for(int j=0;j<2;++j){
				dp[i][j]=0;
			}
		}
		for(int i=0;i<k;++i){
			dp[i+1][1]=max(dp[i][1]+a[i*2+1],dp[i][0]+a[2*i+1]);
			dp[i+1][0]=dp[i][0]+a[2*i];
		}
		ans=max(dp[k][1],dp[k][0]);
		return cout<<ans,0;
	}
	vector<vector<ll>> dp(k+1,vector<ll>(3));
	for(int i=0;i<k+1;++i){
		for(int j=0;j<3;++j){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<k;++i){
		dp[i+1][2]=max(max(dp[i][1]+a[2*i+2],dp[i][0]+a[2*i+2]),dp[i][2]+a[2*i+2]);
        dp[i+1][1]=max(dp[i][1]+a[2*i+1],dp[i][0]+a[2*i+1]);
        dp[i+1][0]=dp[i][0]+a[2*i];
	}
	ans=max(max(dp[k][0],dp[k][1]),dp[k][2]);
	cout<<ans;
	return 0;
}
