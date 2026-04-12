#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+10;
long long int dp[2][maxn][maxn];
int n;
int a[maxn];
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
     cin>>n;
     for(int i=0;i<n;i++){
     	cin>>a[i];
	 }
	 for(int i=n-1;i>=0;i--){
	 	for(int j=i;j<n;j++){
	 		if(i==j){
	 			dp[0][i][j]=a[i];
	 			dp[1][i][j]-=a[i];
			 }
			 else{
			 	dp[0][i][j]=max(a[i]+dp[1][i+1][j],a[j]+dp[1][i][j-1]);
			 	dp[1][i][j]=min(dp[0][i+1][j]-a[i],dp[0][i][j-1]-a[j]);
			 }
		 }
	 }
	 cout<<dp[0][0][n-1];
	 }