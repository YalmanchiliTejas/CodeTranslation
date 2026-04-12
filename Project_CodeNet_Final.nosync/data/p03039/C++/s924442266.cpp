#include <bits/stdc++.h>
using namespace std;

long long MOD=1000000007ll;

long long fac[200010],finv[200010],inv[200010];

void COMinit(){
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<200010;i++){
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

int main(){
	int N,M,K;
	cin >> N >> M >> K;
	long long ans=0;
	COMinit();
	
	for(int d=1;d<=N;d++){
		ans+=1LL*(N-d)*M*M*d;
		ans%=MOD;
	}
	for(int d=1;d<=M;d++){
		ans+=1LL*(M-d)*N*N*d;
		ans%=MOD;
	}
	
	ans*=COM(N*M-2,K-2);
	ans%=MOD;
	cout << ans << endl;
	return 0;
}