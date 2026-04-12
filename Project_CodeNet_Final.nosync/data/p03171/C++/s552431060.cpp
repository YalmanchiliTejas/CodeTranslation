#include <bits/stdc++.h>
using namespace std;
#define modulo 924844033
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000




int main(){
	
	int N;
	cin>>N;
	
	vector<long long> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	
	vector<vector<long long>> dp(N+1,vector<long long>(N+1,0));
	
	for(int j=1;j<=N;j++){
		for(int i=0;i<N;i++){
			if(i+j>N)continue;
			if(j%2==N%2){
				dp[i][j] = max(dp[i][j-1]+a[i+j-1],dp[i+1][j-1]+a[i]);
			}
			else{
				dp[i][j] = min(dp[i][j-1]-a[i+j-1],dp[i+1][j-1]-a[i]);
			}
		}
	}
	
	cout<<dp[0][N]<<endl;
	
    return 0;
}
