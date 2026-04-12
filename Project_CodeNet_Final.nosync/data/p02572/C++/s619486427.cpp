#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int m=1e9+7;
	int n;
	cin>>n;
	long long int a[n];
	for (int i=0;i<n;i++) cin>>a[i];
	long long int dp[n];
	dp[n-1]=a[n-1];
	for (int i=n-2;i>=0;i--) dp[i]=(dp[i+1]+a[i])%m;
	long long int ans=0;
	for (int i=0;i<n-1;i++){
	    ans+=a[i]*dp[i+1];
	    ans%=m;
	}
	cout<<ans<<"\n";
	return 0;
}