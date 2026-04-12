#include <bits/stdc++.h>
using namespace std;


long long dp[110][2][110];
string s;
int k;


long long solve(int n, int N, int flag, int qtd){
	if (n==N){
		if (qtd!=k) return 0;
		else return 1;
	}
	
	if (dp[n][flag][qtd]!=-1) return dp[n][flag][qtd];
	
	if (flag==0){
		int k=s[n]-'0';
		
		if (k==0) dp[n][flag][qtd]=solve(n+1, N, 0, qtd);
		else dp[n][flag][qtd]=solve(n+1, N, 1, qtd)+(k-1)*solve(n+1, N, 1, qtd+1)+solve(n+1, N, 0, qtd+1);
	}
	
	else{
		dp[n][flag][qtd]=solve(n+1, N, 1, qtd)+9*solve(n+1, N, 1, qtd+1);
	}
	
	return dp[n][flag][qtd];

}


int main(){
		cin>>s;
		cin>>k;
		int t=(int)s.size();
		memset(dp, -1, sizeof(dp));
		long long x=solve(0, t, 0, 0);
		
		printf("%lld\n", x);
		



}