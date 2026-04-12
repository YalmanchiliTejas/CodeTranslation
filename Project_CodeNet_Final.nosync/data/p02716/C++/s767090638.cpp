#include<bits/stdc++.h>
using namespace std;
long long int dp[200005];
long long int sum[200005];
long long int yoyo[200005];
int main(){
	int t;
	cin>>t;
	cin>>yoyo[1];
	sum[1]=yoyo[1];
	for(int i=2;i<=t;i++){
		cin>>yoyo[i];
		if(i%2)sum[i]=sum[i-2]+yoyo[i];
	}
	for(int i=2;i<=t;i++){
		if(i%2)dp[i]=max(dp[i-1],dp[i-2]+yoyo[i]);
		else dp[i]=max(sum[i-1],dp[i-2]+yoyo[i]);
	}
	cout<<dp[t]<<endl;
}