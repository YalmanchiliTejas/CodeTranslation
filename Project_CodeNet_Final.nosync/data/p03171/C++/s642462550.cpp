#include <bits/stdc++.h>
using namespace std;


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n;
	cin >> n;
	long long int a[n+1];
	long long int s=0;
	for(int i=0;i<n;i++){
		cin >> a[i+1];
		s+=a[i+1];
	}
	long long int dp[n+1][n+1][2];
	for(int l=1;l<=n;l++){
		if(l==1){
			for(int i=1;i<=n;i++){
				dp[i][i][0]=a[i];
				dp[i][i][1]=0;
			}
		}
		else{
			for(int i=1;i+l-1<=n;i++){
				dp[i][i+l-1][0]=max(a[i]+dp[i+1][i+l-1][1],dp[i][i+l-2][1]+a[i+l-1]);
				dp[i][i+l-1][1]=min(dp[i+1][i+l-1][0],dp[i][i+l-2][0]);
			}
		}
	}
	cout << 2*dp[1][n][0]-s;



	
	




	

}
