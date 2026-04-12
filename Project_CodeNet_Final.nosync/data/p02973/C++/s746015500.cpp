#include<bits/stdc++.h>
using namespace std;
int n,a[100009],dp[100009],ans;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0]=1000000009;
	for(int i=1;i<=n;i++) {
		if(dp[ans]>=a[i]) {
			dp[ans+1]=a[i];
			ans++;
		}
		int l=0,r=ans;
		while(l<r) {
			int m=(l+r)/2;
			if(dp[m]>=a[i]) l=m+1;
			else r=m;
		}
		if(l!=0) dp[l]=a[i];
	}
	cout<<ans<<endl;
	return 0;
}