#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define INF -1e15

int main() {
	int N;
	cin>>N;
	vector<LL> A(N+4);
	for (int i = 0; i < N; i++){
		cin>>A[i];
	}
	vector<vector<LL>> dp(N+4,vector<LL>(3,INF));
	dp[0][0]=A[0];
	dp[1][1]=A[1];
	dp[2][2]=A[2];
	for (int i = 0; i < N; i++){
		if(dp[i][0]!=INF){
			dp[i+2][0]=max(dp[i+2][0],dp[i][0]+A[i+2]);
			dp[i+3][1]=max(dp[i+3][1],dp[i][0]+A[i+3]);
			dp[i+4][2]=max(dp[i+4][2],dp[i][0]+A[i+4]);
		}
		if(dp[i][1]!=INF){
			dp[i+2][1]=max(dp[i+2][1],dp[i][1]+A[i+2]);
			dp[i+3][2]=max(dp[i+3][2],dp[i][1]+A[i+3]);
		}
		if(dp[i][2]!=INF){
			dp[i+2][2]=max(dp[i+2][2],dp[i][2]+A[i+2]);
		}
	}
	if(N%2==0)cout<<max(dp[N-2][0],dp[N-1][1])<<endl;
	else cout<<max(max(dp[N-3][0],dp[N-2][1]),dp[N-1][2])<<endl;
}