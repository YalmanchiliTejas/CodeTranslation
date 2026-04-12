#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
lli a[3002];
lli n;
lli dp[3002][3002];
lli solve(lli i,lli j,lli p);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) dp[i][j]=-1;
	}
	solve(0,n-1,1);
	cout<<dp[0][n-1]<<endl;
}

lli solve(lli i,lli j,lli p){
	if (i>j) return 0;
	if (dp[i][j]!=-1) return dp[i][j];
	if (p==1){
		//if (a[i]>a[j]) dp[i][j]=solve(i+1,j,0)+a[i];
		dp[i][j]=max(solve(i+1,j,0)+a[i],solve(i,j-1,0)+a[j]);
		//else dp[i][j]=solve(i,j-1,0)+a[j];
	}
	else{
		//if (a[i]>a[j]) dp[i][j]=solve(i+1,j,1)-a[i];
		dp[i][j]=min(solve(i+1,j,1)-a[i],solve(i,j-1,1)-a[j]);
		//else dp[i][j]=solve(i,j-1,1)-a[j];		
	}
	return dp[i][j];
}