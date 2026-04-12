#include<bits/stdc++.h>
using namespace std;

int n;
long long arr[3005];
long long DP[3005][3005][2];

long long dp(int L, int R, int turn){
	if(L>R) return 0;
	if(DP[L][R][turn]!=-1) return DP[L][R][turn];
	
	if(turn == 1){
		long long x1 = arr[L] + dp(L+1,R,0);
		long long x2 = arr[R] + dp(L,R-1,0);
		return DP[L][R][turn]  = max(x1,x2);
	} else {
		long long x1 = dp(L+1,R,1);
		long long x2 = dp(L,R-1,1);
		return DP[L][R][turn]  = min(x1,x2);
	}
}

int main(){
	memset(DP,-1,sizeof DP);
	scanf("%d",&n);
	long long tot =0;
	for (int i = 0; i<n;i++){
		scanf("%lld",&arr[i]);
		tot += arr[i];
	}
	long long ans = dp(0,n-1,1);
	printf("%lld\n", ans-(tot-ans));
	return 0;
}