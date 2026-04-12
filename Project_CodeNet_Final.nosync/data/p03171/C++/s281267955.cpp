#include <iostream>
#define ll long long int
using namespace std;

ll max(ll a,ll b){
	if(a>b)return a;
	return b;
}

int main() {
	// your code goes here
	int n;cin>>n;
	ll a[n],sum=0;
	for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
	ll dp[n+1][n];
	
	for(int l=1;l<=n;l++){
		for(int i=0;i<n-l+1;i++){
			int j=i+l-1;
			if(l==1){
				dp[i][j]=a[i];
			}else if(l==2){
				dp[i][j]=max(a[i],a[j]);
			}else{
				ll x1,x2;
				if(dp[i+1][j-1]>dp[i+2][j]){
					x1=a[i]+dp[i+2][j];
				}else{
					x1=a[i]+dp[i+1][j-1];
				}
				
				
				if(dp[i][j-2]>dp[i+1][j-1]){
					x2=a[j]+dp[i+1][j-1];
				}else{
					x2=a[j]+dp[i][j-2];
				}
				
				//int x1=a[i]+max(dp[i+2][j],dp[i+1][j-1]);
				//int x2=a[j]+max(dp[i+1][j-1],dp[i][j-2]);
				dp[i][j]=max(x1,x2);
			}
		}
	}
	
/*	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
*/	
	
	ll ans1=dp[0][n-1];
	sum=sum-ans1;
	ans1-=sum;
	cout<<ans1<<endl;
	
	
	
	return 0;
}