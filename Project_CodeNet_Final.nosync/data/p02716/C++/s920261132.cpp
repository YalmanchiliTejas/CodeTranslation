#include<bits/stdc++.h>
using namespace std;

long long n, a[200003], dp[200003][4]; // 0:all 2, 1: one 3, 2: two 3, 3: one 4

int main(){
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<n;i++){
		for (int j=0;j<4;j++){
			dp[i][j]=-1e15;
		}
	}
	if (n%2==0){
		for (int i=0;i<n;i++){
			dp[i][0]=a[i];
			if (i-2>=0) dp[i][0]+=dp[i-2][0];
			if (i-3>=0){
				dp[i][1]=a[i];
				dp[i][1]+=max(dp[i-2][1],dp[i-3][0]);
			}
		}
		long long ans=dp[n-1][0];
		ans=max(ans,dp[n-2][0]);
		ans=max(ans,dp[n-1][1]);
		cout << ans << "\n";
	}
	else{
		for (int i=0;i<n;i++){
			dp[i][0]=a[i];
			if (i==2) dp[i][1]=a[i];
			if (i==3) dp[i][3]=a[i];
			if (i-2>=0) dp[i][0]+=dp[i-2][0]; // tipe 0
			if (i-3>=0){ // tipe 1
				dp[i][1]=a[i];
				dp[i][1]+=max(dp[i-3][0],dp[i-2][1]);
			}
			if (i-4>=0){ // tipe 3
				dp[i][3]=a[i];
				dp[i][3]+=max(dp[i-4][0],dp[i-2][3]);
			}
			if (i-5>=0){ // tipe 2
				dp[i][2]=a[i];
				dp[i][2]+=max(dp[i-3][1],dp[i-2][2]);
			}
		}
//		cout << dp[n-1][0] << " " << dp[n-2][0] << " " << dp[n-2][1] << " " << dp[n-1][2] << " " << dp[n-1][3] << "\n";
		long long ans=dp[n-1][0];
		ans=max(ans,dp[n-2][0]);
		ans=max(ans,dp[n-2][1]);
		ans=max(ans,dp[n-1][2]);
		ans=max(ans,dp[n-1][3]);
		ans=max(ans,dp[n-1][1]);
		cout << ans << "\n";
	}
}