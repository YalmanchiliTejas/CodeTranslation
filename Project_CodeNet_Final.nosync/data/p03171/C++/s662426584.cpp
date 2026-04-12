#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main(){
	lli n;
	cin>>n;
	vector<lli> a(n);
	for(lli i=0;i<n;i++){
		cin>>a[i];
	}
	vector<vector<lli> > dp(n,vector<lli>(n));
	for(lli i=0;i<n;i++){
		dp[i][i]=a[i];
	}
	for(lli l=2;l<=n;l++){
		for(lli i=0;i<n-l+1;i++){
			lli j=i+l-1;
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
}