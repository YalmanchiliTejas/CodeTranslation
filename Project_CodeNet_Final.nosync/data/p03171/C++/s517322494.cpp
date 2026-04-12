#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main(){
	LL n;
	cin>>n;
	LL a[n];
	for(LL i=0;i<n;i++){
		cin>>a[i];
	}
	LL dp[n+1][n+1][2];
	for(LL i=0;i<n;i++){
		for(LL j=0;j<n;j++){
			dp[i][j][0]=dp[i][j][1]=0;
		}
	}
	
	
	for(LL i=0;i<n;i++){
		for(LL j=0,k=j+i;k<n;j++){
			
			if(i==0){
				dp[j][k][0]=a[j];
			}
			else {
				if(a[j]+dp[j+1][k][1]>a[k]+dp[j][k-1][1]){
					
					dp[j][k][0]=a[j]+dp[j+1][k][1];
					dp[j][k][1]=dp[j+1][k][0];
				}
				else{
					
					dp[j][k][0]=a[k]+dp[j][k-1][1];
					dp[j][k][1]=dp[j][k-1][0];
				}
			}
//			k=j+i+1;
//			cout<<j<<" "<<k<<" "<<dp[j][k][0]<<" "<<dp[i][j][1]<<endl;
			k+=1;
		}
	}
	cout<<(dp[0][n-1][0]-dp[0][n-1][1])<<endl;
	return 0;
}