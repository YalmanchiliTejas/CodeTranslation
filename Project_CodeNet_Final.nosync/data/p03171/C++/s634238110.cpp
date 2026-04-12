#include<bits/stdc++.h>
using namespace std;

int n;
long long a[3003], dp[3003][3003]; // dp[l][r]

int main(){
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int len=0;len<n;len++){
		for (int i=0;i<n;i++){
			if (i+len>=n) continue;
			if (len==0) dp[i][i]=a[i];
			else if (len&1){ // even size, Jiro's turn
				dp[i][i+len]=min(dp[i][i+len-1]-a[i+len],dp[i+1][i+len]-a[i]);
			}
			else{ // odd size, Taro's turn
				dp[i][i+len]=max(dp[i][i+len-1]+a[i+len],dp[i+1][i+len]+a[i]);
			}
		}
	}
//	for (int i=0;i<n;i++){
//		for (int j=i;j<n;j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	cout << (n%2==0 ? -dp[0][n-1] : dp[0][n-1]) << "\n";
}