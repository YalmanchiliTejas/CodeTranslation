#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	int a[n];
	ll sum1,sum2;
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll pre[n+1];
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i-1];}
	ll dp[n][n];
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n;j++){
			if(i>j)  dp[i][j]=0;
			else if(i==j)  dp[i][j]=a[i];
			else{
				sum1=pre[j+1]-pre[i+1];
				sum2=pre[j]-pre[i];
				dp[i][j]=max(a[i]+sum1-dp[i+1][j],a[j]+sum2-dp[i][j-1]);
			}
		}
	}
	ll ans=2*dp[0][n-1]-pre[n];
		cout<<ans<<endl;
	}