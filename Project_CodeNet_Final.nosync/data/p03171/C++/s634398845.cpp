#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[3003];
ll dp[3003][3003];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; 
	cin>>n; 
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dp[i][i] = (n%2 ? a[i]:-a[i]);
	for(int l=n;l>=1;l--){
		for(int r=l+1;r<=n;r++){
			int len = r-l+1;
			if(len%2==n%2){
				dp[l][r] = max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
			}
			else{
				dp[l][r] = min(dp[l+1][r]-a[l],dp[l][r-1]-a[r]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
