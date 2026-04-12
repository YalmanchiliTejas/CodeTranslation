#include<bits/stdc++.h>
using namespace std;
#define lli long long int
	lli dp[3000][3000][2];
		lli arr[3000];
lli solve(lli low,lli high,lli mov){
	if(low>high)
	return 0;
	if(dp[low][high][mov]!=0)
	return dp[low][high][mov];
	if(low==high){
		if(mov==0)
	return dp[low][high][mov]=arr[low];
	else
	return dp[low][high][mov]=-arr[low];
	}
	if(mov==0)
	dp[low][high][mov]=max(arr[low]+solve(low+1,high,1-mov),arr[high]+solve(low,high-1,1-mov));
	else
	dp[low][high][mov]=min(-arr[low]+solve(low+1,high,1-mov),-arr[high]+solve(low,high-1,1-mov));
	return dp[low][high][mov];
}
int main(){
	lli n;
	cin>>n;
	for(lli i=0;i<n;i++)
	cin>>arr[i];
	for(lli i=0;i<n;i++){
		for(lli j=0;j<n;j++){
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	solve(0,n-1,0);
//	for(lli i=0;i<n;i++){
//		for(lli j=0;j<n;j++){
//			cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<"     ";
//		}
//		cout<<"\n";
//	}
	cout<<dp[0][n-1][0];
	return 0;
}
