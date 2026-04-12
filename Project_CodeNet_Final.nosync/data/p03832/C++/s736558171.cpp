#include <bits/stdc++.h>
using namespace std;

long long MOD=1000000007LL;

long long fac[1000000],finv[1000000],inv[1000000];

long long dp[1111][1111];

void COMinit(){
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<1000000;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}

long long COM(int n,int k){
	if(n<k)return 0;
	if(n<0 || k<0)return 0;
	return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

long long MODpow(long long a,int b){
	if(b==0)return 1;
	if(b%2==0){
		long long t=MODpow(a,b/2);
		return (t*t)%MOD;
	}
	return (a*MODpow(a,b-1))%MOD;
}

int main(){
	int N,A,B,C,D;
	cin >> N >> A >> B >> C >> D;
	
	COMinit();
	
	for(int i=0;i<=N;i++)dp[i][0]=1;
	for(int i=1;i<=N;i++)for(int j=0;j<=N;j++){
		dp[i][j]=dp[i-1][j];
		if(i<A || i>B)continue;
		for(int k=C;k<=min(D,j/i);k++){
			long long add=dp[i-1][j-i*k]*COM(N-(j-i*k),i*k);
			add%=MOD;
			add*=fac[i*k];
			add%=MOD;
			add*=MODpow(finv[i],k);
			add%=MOD;
			add*=finv[k];
			add%=MOD;
			dp[i][j]+=add;
			dp[i][j]%=MOD;
		}
	}
	cout << dp[N][N] << endl;
	return 0;
}