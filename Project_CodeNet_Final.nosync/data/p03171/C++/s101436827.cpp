#include<bits/stdc++.h>
using namespace std;
long long dp[3005][3005];
long long a[3005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int flag=((n&1)?1:-1);
	for(int i=0;i<n;i++) dp[i][i]=a[i]*flag;
	for(int i=1;i<n;i++,flag=-flag){
		for(int l=0;l+i<n;l++){
			int r=l+i;
			if(~flag){
				dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r]);
			}
			else{
				dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
			}
		}
	}
	cout<<dp[0][n-1];
	return 0;
}