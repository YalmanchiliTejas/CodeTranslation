#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const LL mod=1e9+7;
const int Max_Num=2e5+10;

LL F[Max_Num], Finv[Max_Num];

LL modpow(LL x, LL n){
	LL r=1;
	while(n){
		if(n&1) r=r*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return r;
}

LL modinv(LL x){
	LL m=mod, u=1, v=0;
	while(m){
		LL t=x/m;
		x-=t*m; swap(x,m);
		u-=t*v; swap(u,v);
	}
	u%=mod;
	if(u<0) u+=mod;
	return u;
}

void fact(){
	F[0]=1;
	rep(i,Max_Num-1){
		F[i+1]=F[i]*(i+1);
		F[i+1]%=mod;
	}
	rep(i,Max_Num) Finv[i]=modinv(F[i]);
}

LL comb(LL n, LL k){
	LL res=F[n];
	res*=Finv[k]*Finv[n-k]%mod;
	return res%mod;
}

int main(){
	fact();
	LL N, M, K;
	cin >> N >> M >> K;
	vector<LL> dist(Max_Num);
	LL ans=0;
	for(LL dx=1; dx<=N-1; dx++){
		LL res=M*M%mod*(N-dx);
		res%=mod;
		dist[dx]+=res;
	}
	for(LL dy=1; dy<=M-1; dy++){
		LL res=N*N%mod*(M-dy);
		res%=mod;
		dist[dy]+=res;
	}
	for(LL d=1; d<Max_Num; d++){
		ans+=comb(N*M-2,K-2)*dist[d]%mod*d;
		ans%=mod;
	}
	cout << ans << endl;

	return 0;
}