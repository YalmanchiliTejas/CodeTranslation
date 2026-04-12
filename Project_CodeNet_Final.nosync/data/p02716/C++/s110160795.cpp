#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dat[1<<18];
ll sum[1<<18];
ll dp[1<<18];
ll n;
int main(){
	cin>>n;
	for(ll i=0;i<n;i++) {
		cin>>dat[i];
		if(i>=2 and i%2==0) sum[i]=dat[i]+sum[i-2];
		else if(i==0) sum[i]=dat[i];
	}
	for(ll i=0;i<n;i++){
		if(i&1){
			dp[i]=max(dp[i-2]+dat[i] , sum[i-1]);
		}
		else{
			dp[i]=max(dp[i-2]+dat[i] , dp[i-1]);
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
