#include <bits/stdc++.h>
using namespace std;

long long mINF=-9999999999999999LL;

int main(){
	int N;
	cin >> N;
	vector<long long> A(N);
	for(auto &i:A)cin >> i;
	
	long long dp[N+1][3];
	for(int i=0;i<N+1;i++)for(int j=0;j<3;j++)dp[i][j]=mINF;
	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][1]=dp[0][2]=dp[1][2]=0;
	dp[1][0]=A[0];
	dp[2][1]=A[1];
	if(N%2==1)dp[3][2]=A[2];
	
	for(int i=2;i<N;i++){
		dp[i+1][0]=max(dp[i+1][0],dp[i-1][0]+A[i]);
		dp[i+1][1]=max(dp[i+1][1],dp[i-1][1]+A[i]);
		dp[i+1][1]=max(dp[i+1][1],dp[i-2][0]+A[i]);
		if(N%2==1 && i>2){
			dp[i+1][2]=max(dp[i+1][2],dp[i-1][2]+A[i]);
			dp[i+1][2]=max(dp[i+1][2],dp[i-2][1]+A[i]);
			dp[i+1][2]=max(dp[i+1][2],dp[i-3][0]+A[i]);
		}
	}
	long long ans;
	if(N%2==0)ans=max(dp[N-1][0],dp[N][1]);
	if(N%2==1)ans=max(max(dp[N-2][0],dp[N-1][1]),dp[N][2]);
	cout << ans << endl;
	return 0;
}