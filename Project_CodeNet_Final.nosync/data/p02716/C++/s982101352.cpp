#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e18;
ll dp[200005][3], arr[200005];
int n;
ll f(int i, int skip){
	if(i>=n){
		if(skip<=1) return 0ll;
		return -INF;
	}
	if(dp[i][skip]!=-INF) return dp[i][skip];
	dp[i][skip]=f(i+2, skip)+arr[i];
	if(skip>0) dp[i][skip]=max(dp[i][skip], f(i+1, skip-1));
	return dp[i][skip];
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		for(int j=0; j<3; j++)
			dp[i][j]=-INF;
	}
	ll ans=f(0, (n&1)?2:1);
	if(n&1){
		ll tmp=0ll, mn=INF;
		for(int i=0; i<n; i+=2){
			tmp+=arr[i];
			if(mn>arr[i]) mn-=arr[i];
		}
		tmp-=mn;
		ans=max(ans, tmp);
	}
	cout<<ans<<endl;
}