#include<bits/stdc++.h>
using namespace std;
 
int n;
long long sum[5003][5003];
long long dp[5003][5003];
long long a[5003];
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum[i][j] = sum[i][j-1] + a[j];
		}
	}
	
	for(int j=1;j<=n;j++){
		for(int i=j;i>0;i--){
			dp[i][j] = max(a[j] + sum[i][j-1] - dp[i][j-1],a[i] + sum[i+1][j] - dp[i+1][j]);
		}
	}
	
	cout<<2*dp[1][n]-sum[1][n]<<endl;
	
	return 0;
}
