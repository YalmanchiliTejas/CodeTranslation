#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=0;
	cin>>n;
	long long arr[n+1];
	memset(arr,0,sizeof(arr));
	long long totalSum=0;
	for(int i=1;i<=n;i++) cin>>arr[i], totalSum+=arr[i];
	long long prefixSum[n+1];
	memset(prefixSum,0,sizeof(prefixSum));
	for(int i=1;i<=n;i++) prefixSum[i]=arr[i]+prefixSum[i-1];
    long long dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	int len=0;
	while(++len<=n){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			if (len==1)
			   dp[i][j]=arr[i];
			else{
				dp[i][j]=max(arr[i]+prefixSum[j]-prefixSum[i]-dp[i+1][j],
				          arr[j]+prefixSum[j-1]-prefixSum[i-1]-dp[i][j-1]);
			}
		}
	}
	// cout<<"start -- "<<endl;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++)
	// 	   cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<2*dp[1][n]-totalSum<<endl;
	return 0;
}