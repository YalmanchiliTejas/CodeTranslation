#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin>>N;
	vector<long long>a(N);
	vector<vector<long long> >dp(N,vector<long long>(N));
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N;i++) dp[i][i]=a[i];
	for(int j=1;j<N;j++)
		for(int i=0;i+j<N;i++)
			dp[i][i+j]=max(a[i]-dp[i+1][i+j],a[i+j]-dp[i][i+j-1]);
	cout<<dp[0][N-1]<<"\n";
	return 0;
}
