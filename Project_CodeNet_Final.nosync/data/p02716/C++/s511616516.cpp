#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;
const int MAX_N = 200000;
typedef long long int64;
int N;
int A[MAX_N+1];
int64 dp[3][MAX_N+1];
int64 solve(){
	memset(dp,0x3f,sizeof(dp));

	for (int i = 0; i < N; ++i){
		dp[0][i] = A[i];
		if(i-2 >= 0)	dp[0][i] += dp[0][i-2];
	}

	//dp[1][1] = A[0]+A[1];
	for (int i = 0; i < N; ++i){
		if(i-1 >= 0)	dp[1][i] = min(dp[1][i],dp[0][i-1]+A[i]);
		if(i-2 >= 0)	dp[1][i] = min(dp[1][i],dp[1][i-2]+A[i]);
	}

	//dp[2][2] = A[0]+A[1]+A[3];
	for (int i = 0; i < N; ++i){
		if(i-1 >= 0)	dp[2][i] = min(dp[2][i],dp[1][i-1]+A[i]);
		if(i-2 >= 0)	dp[2][i] = min(dp[2][i],dp[2][i-2]+A[i]);
	}

	int64 total = 0;
	for (int i = 0;i < N; ++i)
		total += A[i];

	int64 ret = dp[0][N-1];
	if( N % 2 == 0){
		ret = min(ret,dp[0][N-2]);
		ret = min(ret,dp[1][N-2]);
		return total - ret;
	}

	ret = min(ret,dp[1][N-1]);
	ret = min(ret,dp[1][N-2]);

	ret = min(ret,dp[2][N-2]);




	return total - ret;
}
int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
		scanf("%d",A+i);
	int64 ans = solve();
	printf("%lld\n",ans);
}
