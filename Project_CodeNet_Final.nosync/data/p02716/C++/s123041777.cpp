#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 10000000000000000


int main() {
	
	long long ans  = -Inf;
	
	int N;
	cin>>N;
	
	vector<long long> A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	

	long long t = 0;
	for(int i=1;i<N;i+=2){
		t += A[i];
	}
	ans = max(ans,t);
	
	vector<vector<long long>> dp(N+1,vector<long long>(2+(N%2),-Inf));
	int K = 2+(N%2);
	dp[0][0] = A[0];
	dp[1][1] = A[1];
	if(N%2==1)dp[2][2] = A[2];
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			if(dp[i][j]<=-Inf)continue;
			if(i==N-1){
				dp[N][j] = max(dp[N][j],dp[i][j]);
			}
			if(i+2==N&&j+1<K){
				dp[N][j+1] = max(dp[N][j+1],dp[i][j]);
			}
			if(i+2<N){
				dp[i+2][j] = max(dp[i+2][j],dp[i][j]+A[i+2]);
			}
			for(int k=0;k<2;k++){
				if(i+3+k==N&&j+2+k<K){
					dp[N][j+2+k] = max(dp[N][j+2+k],dp[i][j]);
				}
				if(i+3+k<N&&j+1+k<K){
					dp[i+k+3][j+1+k] = max(dp[i+3+k][j+1+k],dp[i][j]+A[i+3+k]);
				}
			}
		}
	}

	
	ans = max(ans,dp.back().back());
		
		
	
	cout<<ans<<endl;
	
    return 0;
}
