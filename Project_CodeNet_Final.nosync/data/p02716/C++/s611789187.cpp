#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int a[maxn];
long long dp[maxn],sum[maxn];
int main(){
	int n,i;
	cin>>n; 
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		if(i%2)
			sum[i]=sum[i-1]+a[i];
		else
			sum[i]=sum[i-1];
	for(i=2;i<=n;i++)
		if(i%2)
			dp[i]=max(dp[i-2]+a[i],dp[i-1]);
		else 
			dp[i]=max(dp[i-2]+a[i],sum[i-1]);
	cout<<dp[n]<<endl;
	return 0;
}