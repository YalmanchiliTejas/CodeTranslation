#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,K,x,y,p,q;
	cin>>n;
	vector<long long>A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	long long dp[n][n];
	for(int i=0;i<n;i++){
		dp[i][i]=A[i];
	}
	for(int k=1;k<n;k++){
		for(int i=0;i<n-k;i++){
			int j=i+k;
			dp[i][j]=max(A[i]-dp[i+1][j],A[j]-dp[i][j-1]);
		}
	}
	cout<<dp[0][n-1]<<"\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}