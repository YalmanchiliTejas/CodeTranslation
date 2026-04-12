#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//const long long int MOD=1000000007;
const int MOD=1000000007;
//const long long int MOD=998244353;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>K>>M;
	vector<vector<vector<long long int>>>dp(N+1,vector<vector<long long int>>(N+1,vector<long long int>(1024)));
	dp[0][0][0]=1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=i;j++){
			if(i==j&&i==N)break;
			for(int k=0;k<1024;k++){
				if(i<N){
					int bef=MOD;
					for(int l=0;l<10;l++){
						if((k>>l)%2==0){
							bef=l+1;
							break;
						}
					}
					if(bef<=K){
						int bi=k;
						bi<<=1;
						bi&=1023;
						dp[i+1][j][bi]+=dp[i][j][k];
						dp[i+1][j][bi]%=M;
					}
				}
				if(i>j){
					int rbef=MOD;
					int ubef=MOD;
					if(!j){
						rbef=0;
					}
					else{
						for(int l=0;l<10;l++){
							if((k>>l)&1){
								rbef=l+1;
								break;
							}
						}
					}
					int cnt=0;
					for(int l=0;l<10;l++){
						if((k>>l)%2==0){
							cnt++;
							if(cnt==i-j){
								ubef=l+1;
								break;
							}
						}
					}
					if(rbef<=K&&ubef<=K){
						int bi=k;
						bi<<=1;
						bi|=1;
						bi&=1023;
						dp[i][j+1][bi]+=dp[i][j][k];
						dp[i][j+1][bi]%=M;
					}
				}
			}
		}
	}
	long long int ans=0;
	for(int i=0;i<1024;i++){
		ans+=dp[N][N][i];
		ans%=M;
	}
	cout<<ans<<endl;
	return 0;
}
