#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
int n,a[3334],dp[3334][3334];
signed main(){
	cin>>n;
	rep(i,n)cin>>a[i];
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			if((n-i-j-1)%2==0){//taro
				dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
			}
			else{//jiro
				dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}
