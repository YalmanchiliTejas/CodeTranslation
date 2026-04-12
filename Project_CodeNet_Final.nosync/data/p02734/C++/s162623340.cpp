#include  <bits/stdc++.h>
using namespace std;

#define MAX 3010
#define MOD 998244353

int N,S;

long long dp[MAX][MAX];
int l[MAX];

long long solve(int n, int soma){
	if (soma==S) return N-n+1;
	if (n==N) return 0;
	if (dp[n][soma]!=-1) return dp[n][soma];
	
	
	dp[n][soma]=0;
	
	if (soma+l[n]<=S) dp[n][soma]+=solve(n+1,soma+l[n]);
	
	dp[n][soma]+=solve(n+1,soma);
	
	return dp[n][soma]%MOD;

}




int main(){
	memset(dp,-1,sizeof(dp));

	cin>>N>>S;
	
	for (int i=0; i<N; i++) cin>>l[i];
	
	long long soma=0;
	
	for (int i=0; i<N; i++){
		soma=(soma%MOD+solve(i,0)%MOD)%MOD;
	
	}
	
	
	cout<<soma<<endl;


}
